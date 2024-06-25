#include "ScalarConverter.hpp"
#include <limits>
#include <cctype>
#include <sstream>
#include <iostream>


ScalarType detectScalarType(const std::string& str) {
	// Check if the str is a single character
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])) {
		return CHAR;
	}

	// Check if the str can be parsed as an integer
	std::istringstream intStream(str);
	int intValue;
	if ((intStream >> intValue) && (intStream.eof())) {
		return INT;
	}

	// Check if the str can be parsed as a float
	std::istringstream floatStream(str);
	float floatValue;
	if (floatStream >> floatValue) {
		char c;
		if (floatStream >> c) { // Attempt to read the next character
			 if ((c == 'f' || c == 'F') && (floatStream.peek(), floatStream.eof())) {  // 'f' or 'F' is the last character, valid float literal
				return FLOAT;
			}
		}
	}

	// Check if the str can be parsed as a double
	std::istringstream doubleStream(str);
	double doubleValue;
	if ((doubleStream >> doubleValue) && (doubleStream.eof())) {
		return DOUBLE;
	}

	return UNKNOWN;
}

void convertChar(const std::string &str)
{
	char charValue = str[0];
	std::cout << "Char: " << charValue << std::endl;
	std::cout << "Int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "Float: " << static_cast<float>(charValue) << "f" <<std::endl;
	std::cout << "Double: " << static_cast<double>(charValue) << std::endl;
}
void convertInt(const std::string &str)
{
	int intValue;
	std::istringstream(str) >> intValue;
	std::cout << "Char: " << static_cast<char>(intValue) << std::endl;
	std::cout << "Int: " << intValue << std::endl;
	std::cout << "Float: " << static_cast<float>(intValue) << "f"<<std::endl;
	std::cout << "Double: " << static_cast<double>(intValue) << std::endl;
}
void convertFloat(const std::string &str)
{
	float floatValue;
	std::istringstream(str) >> floatValue;
	std::cout << "Char: " << static_cast<char>(floatValue) << std::endl;
	std::cout << "Int: " << static_cast<int>(floatValue) << std::endl;
	std::cout << "Float: " << floatValue << "f"<<std::endl;
	std::cout << "Double: " << static_cast<double>(floatValue) << std::endl;
}
void convertDouble(const std::string &str)
{
	double doubleValue;
	std::istringstream(str) >> doubleValue;
	std::cout << "Char: " << static_cast<char>(doubleValue) << std::endl;
	std::cout << "Int: " << static_cast<int>(doubleValue) << std::endl;
	std::cout << "Float: " << static_cast<float>(doubleValue) <<"f"<<std::endl;
	std::cout << "Double: " << doubleValue << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
	ScalarType type = detectScalarType(str);

	switch (type) {
		case CHAR: {
			convertChar(str);
			break;
		}
		case INT: {
			convertInt(str);
			break;
		}
		case FLOAT: {
			convertFloat(str);
			break;
		}
		case DOUBLE: {
			convertDouble(str);
			break;
		}
		default:
			std::cout << "Unknown type." << std::endl;
	}
}


