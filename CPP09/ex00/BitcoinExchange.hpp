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
		BitcoinExchange(const BitcoinExchange & cpy);
		const BitcoinExchange & operator=(const BitcoinExchange & src);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void parse_db();
		void convert(std::string &file);
		void display_conversion(time_t date, float value);
		time_t get_closest_date(time_t date);

		class InvalidInputException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		void print_db();

};
#endif
