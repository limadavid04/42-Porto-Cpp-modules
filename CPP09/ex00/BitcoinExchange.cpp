#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>
#include <stdexcept>
#include <iomanip>

BitcoinExchange::BitcoinExchange(std::string &file) {
	parse_db(file);
}
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1) return false;
	const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return day <= daysInMonth[month - 1];
}
std::string timeToString(time_t time) {
    std::tm* tm = std::localtime(&time); // Convert time_t to tm struct
    char buffer[11]; // Buffer to hold the formatted string. Format is YYYY-MM-DD\0, so 11 characters are needed.
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm); // Format the tm struct into the buffer
    return std::string(buffer); // Convert buffer to std::string and return
}
void BitcoinExchange::print_db() {
	for (std::map<time_t, float>::const_iterator it = _exchange_rates_db.begin(); it != _exchange_rates_db.end(); ++it) {
		std::cout << timeToString(it->first) << "," << it->second << '\n';
	}
}

time_t BitcoinExchange::parse_date(std::string date_str)
{
	std::istringstream dateStream(date_str);
	int year = 0, month = 0, day = 0;
	char dash1, dash2;
	std::tm tm = {};
	dateStream >> year >> dash1 >> month >>dash2 >>day;
	if (!dateStream.eof() || dateStream.fail() || dash1 != '-' || dash2 != '-')
		throw BitcoinExchange::LineSyntaxErrorException("found while parsing date");
	if (!isValidDate(year, month, day))
		throw BitcoinExchange::InvalidDateException(date_str);
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	time_t myTimeT = mktime(&tm);
	if (myTimeT == (time_t)-1)
		throw BitcoinExchange::InvalidDateException("Failed to convert tm to time_t.");
	return myTimeT;
}

void BitcoinExchange::parse_db(std::string &file)
{
	std::ifstream csv_file(file.c_str());
	std::string line;

	float rate = 0;
	while (std::getline(csv_file, line))
	{
		time_t date;
		std::istringstream ss(line);
		std::string date_str, rate_str;
		std::getline(ss, date_str, ',');
		std::getline(ss, rate_str);
		if (rate_str.empty())
		{
			std::cerr << "No comma was found in the line." <<std::endl;
			continue;
		}
		std::istringstream rate_ss(rate_str);

		try {
			date = parse_date(date_str);
			rate_ss >> rate;
			bool insertion_status = (_exchange_rates_db.insert(std::make_pair(date, rate))).second;
			if (!insertion_status)
			{
				std::cerr << "Insertion failed, key already exists: " << date << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	csv_file.close();
}

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& msg) : _message("Invalid Date: " + msg) {}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return _message.c_str();
}

BitcoinExchange::LineSyntaxErrorException::LineSyntaxErrorException(const std::string& msg) : _message("Invalid Line syntax: " + msg) {}

const char* BitcoinExchange::LineSyntaxErrorException::what() const throw() {
	return _message.c_str();
}
