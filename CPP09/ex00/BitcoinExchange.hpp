#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <ctime>
#include <map>
#include <string>
#include <stdexcept>
class BitcoinExchange {
	private:
		std::map<time_t,double> exchange_rates_db;
	public:
		time_t parse_date(std::string date_str);
		void parse_db(char *file);
		class InvalidDateException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class InvalidLineFormatException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};
#endif
