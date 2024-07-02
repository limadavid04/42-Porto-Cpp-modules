#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <ctime>
#include <map>
#include <string>
#include <stdexcept>
class BitcoinExchange {
	private:
		std::map<time_t,float> _exchange_rates_db;
		std::string _data_base_path;
	public:
		BitcoinExchange();
		static time_t parse_date(std::string &date_str);
		time_t get_closest_date(time_t date);
		void display_conversion(time_t date, float value);
		float parse_exchange_rate(std::string &rate_str);
		void parse_db();
		void convert(std::string &file);
		// class InvalidDateException: public std::exception {
		// 	private:
		// 			std::string _message;
		// 	public:
		// 		InvalidDateException(const std::string& msg);
		// 		virtual const char* what() const throw();
		// 		virtual ~InvalidDateException() throw() {} // Add throw() to match std::exception

		// };
		class InvalidInputException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		void print_db();

};
#endif
