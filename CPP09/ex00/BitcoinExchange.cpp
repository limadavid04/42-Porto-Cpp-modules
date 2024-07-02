#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
	if (year < 0 || month < 1 || month > 12 || day < 1) return false;
	const int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return day <= daysInMonth[month - 1];
}
//make a separate function to parse the rate and check for numeric limits
// void parse_exchange_rate(std::string rate);
time_t BitcoinExchange::parse_date(std::string date_str)
{
	std::istringstream dateStream(date_str);
	int year = 0, month = 0, day = 0;
	char dash1, dash2;
	std::tm tm = {};
	dateStream >> year >> dash1 >> month >>dash2 >>day;
	if (!dateStream.eof() || dateStream.fail() || dash1 != '-' || dash2 != '-') {
		std::cerr << "Parsing error while parsing date: " << dateStream << std::endl;
		continue;
	}
	if (!isValidDate(year, month, day))
	{
		std::cerr << "Invalid Date: " << year<<dash1<<month<<dash2<<day<<std::endl;
		continue ;
	}
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	time_t myTimeT = mktime(&tm);
	if (myTimeT == (time_t)-1)
	{
		std::cout << "Failed to convert tm to time_t." << std::endl;
		continue;
	}
	return myTimeT;
}
void BitcoinExchange::parse_db(char *file)
{
	std::map<time_t,double> exchange_rates_db;
	std::ifstream csv_file(file);
	std::string line;

	float rate = 0;
	while (std::getline(csv_file, line))
	{
		time_t date;
		std::istringstream ss(line);
		std::string date_str, rate_str;
        std::getline(ss, date_str, ',');
        std::getline(ss, rate_str);
		if (rate_str.empty()) {
			std::cout << "No comma was found in the line." << std::endl;
		date = parse_date(date_str);

		std::pair<std::map<time_t, double>::iterator, bool> result = exchange_rates_db.insert(std::make_pair(date, rate));
		if (!result.second) {
			std::cerr << "Insertion failed, key already exists: " << date << std::endl;
		}
	}
		csv_file.close();
}
const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Invalid Date: ");
}
const char* BitcoinExchange::InvalidLineFormatException::what() const throw() {
	return ("Grade is too low");
}
