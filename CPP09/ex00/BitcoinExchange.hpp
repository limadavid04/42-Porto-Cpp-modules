#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <ctime>
#include <map>
#include <string>
#include <stdexcept>
class BitcoinExchange {
	private:
		std::map<time_t,float> _exchange_rates_db;
	public:
		BitcoinExchange(std::string &file);
		static time_t parse_date(std::string date_str);
		float parse_exchange_rate(std::string rate_str);
		void parse_db(std::string &file);
		class InvalidDateException: public std::exception {
			private:
					std::string _message;
			public:
				InvalidDateException(const std::string& msg);
				virtual const char* what() const throw();
				virtual ~InvalidDateException() throw() {} // Add throw() to match std::exception

		};
		class LineSyntaxErrorException : public std::exception {
			private:
					std::string _message;
			public:
				LineSyntaxErrorException(const std::string& msg);
				virtual const char* what() const throw();
				virtual ~LineSyntaxErrorException() throw() {}
		};
		void print_db();

};
#endif
