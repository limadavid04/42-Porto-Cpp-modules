#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <limits>
#include <algorithm>

const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	(void)src;
	return *this;
};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	(void)cpy;
};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange() : _exchange_rates_db(), _data_base_path("data.csv") {
	try {
		parse_db();
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
static bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1) return false;
	const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return day <= daysInMonth[month - 1];
}

static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

std::string timeToString(time_t time) {
	std::tm* tm = std::localtime(&time); // Convert time_t to tm struct
	char buffer[11]; // Buffer to hold the formatted string. Format is YYYY-MM-DD\0, so 11 characters are needed.
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm); // Format the tm struct into the buffer
	return std::string(buffer); // Convert buffer to std::string and return
}

void BitcoinExchange::print_db() {
	if (_exchange_rates_db.empty()) {
		std::cout << "The exchange rates database is empty, please try passing a Database first." << std::endl;
		return ;
	}
	for (std::map<time_t, float>::const_iterator it = _exchange_rates_db.begin(); it != _exchange_rates_db.end(); ++it) {
		std::cout << timeToString(it->first) << "," << it->second << '\n';
	}
}

float parse_value(std::string &value_str) {
	float value;
	rtrim(value_str);
	if (value_str.empty())
		throw BitcoinExchange::InvalidInputException();
	std::istringstream rate_ss(value_str);
	if (!(rate_ss >> value) || !rate_ss.eof() )
		throw BitcoinExchange::InvalidInputException();
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");

	return value;
}

time_t parse_date(std::string &date_str)
{
	rtrim(date_str);
	std::istringstream date_ss(date_str);
	int year = 0, month = 0, day = 0;
	char dash1, dash2;
	std::tm tm = {};
	date_ss >> year >> dash1 >> month >>dash2 >>day;
	if (!date_ss.eof()|| date_ss.fail() || dash1 != '-' || dash2 != '-')
		throw BitcoinExchange::InvalidInputException();
	if (!isValidDate(year, month, day))
		throw BitcoinExchange::InvalidInputException();
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	time_t myTimeT = mktime(&tm);
	// if (myTimeT == (time_t)-1)
	// 	throw BitcoinExchange::InvalidDateException("Failed to convert tm to time_t.");
	return myTimeT;
}

float parse_exchange_rate(std::string &rate_str)
{
	float rate;
	rtrim(rate_str);
	if (rate_str.empty())
		throw BitcoinExchange::InvalidInputException();
	std::istringstream rate_ss(rate_str);
	if (!(rate_ss >> rate) || !rate_ss.eof() || rate < 0 || rate > std::numeric_limits<float>::max())
		throw std::runtime_error("Invalid exchange rate");
	return rate;
}

void BitcoinExchange::parse_db()
{
	std::ifstream csv_file(_data_base_path.c_str());
	std::string line;
	float rate = 0;

	if (!csv_file.is_open())
		throw std::runtime_error("Error: could not open file.");
	//skip title
	while (std::getline(csv_file, line))
	{
		if (!line.empty())
			break;
	}
	while (std::getline(csv_file, line))
	{
		if (line.empty())
			continue ;
		time_t date;
		std::istringstream ss(line);
		std::string date_str, rate_str;
		std::getline(ss, date_str, ',');
		std::getline(ss, rate_str);

		try {
			date = parse_date(date_str);
			rate = parse_exchange_rate(rate_str);
			bool insertion_status = (_exchange_rates_db.insert(std::make_pair(date, rate))).second;
			if (!insertion_status)
				throw std::runtime_error("Insertion into DB failed: key already exists.");
		} catch (BitcoinExchange::InvalidInputException & e) {
			std::cerr << e.what() <<" => "<< line <<std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	csv_file.close();
}

time_t BitcoinExchange::get_closest_date(time_t date)
{
	std::map<time_t, float>::iterator it = _exchange_rates_db.lower_bound(date);
	if (it == _exchange_rates_db.end()) {
		if (!_exchange_rates_db.empty()) {
			it--;
		}
	} else if (it != _exchange_rates_db.begin() && it->first != date) {

		--it;
	}
	if (it != _exchange_rates_db.end()) {
		return it->first;
	}
	else {
		throw std::runtime_error("Data Base is empty");
	}
}

void BitcoinExchange::display_conversion(time_t date, float value)
{
		time_t key = get_closest_date(date);
		std::cout << timeToString(date) << " >= " << value << " = " << (value * _exchange_rates_db.at(key)) << std::endl;
}

void BitcoinExchange::convert(std::string &file) {
	std::ifstream csv_file(file.c_str());
	std::string line;
	float value = 0;

	if (_exchange_rates_db.empty())
		throw std::runtime_error("Error: Data Base is empty.");
	if (!csv_file.is_open())
		throw std::runtime_error("Error: could not open file.");
	//check first line;
	while (std::getline(csv_file, line))
	{
		if (!line.empty())
			break;
	}
	while (std::getline(csv_file, line))
	{
		if (line.empty())
			continue ;
		time_t date;
		std::istringstream ss(line);
		std::string date_str, value_str;
		std::getline(ss, date_str, '|');
		std::getline(ss, value_str);
		try {
			date = parse_date(date_str);
			value = parse_value(value_str);
			display_conversion(date, value);
		} catch (BitcoinExchange::InvalidInputException & e) {
			std::cerr << e.what() <<" => "<< line <<std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	csv_file.close();
}
const char* BitcoinExchange::InvalidInputException::what() const throw()
{
	return ("Error: bad input");
}

