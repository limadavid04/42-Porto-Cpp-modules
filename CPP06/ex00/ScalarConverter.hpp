#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>


class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &cpy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter &src);
	public:
		static void convert(const std::string &str);
};

#endif
