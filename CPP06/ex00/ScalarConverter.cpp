#include "ScalarConverter.hpp"
#include <limits>
#include <cctype>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>

enum ScalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

ScalarConverter::ScalarConverter(){};

ScalarConverter::~ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter &cpy) {
	(void)cpy;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return (*this);
};

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
			 if ((c == 'f' || c == 'F') && (floatStream.peek(), floatStream.eof())) // 'f' or 'F' is the last character, valid float literal
				return FLOAT;
			}
	}
	if (str == "-inff" || str == "+inff" || str == "inff" ||str == "nanf")
		return FLOAT;
	// Check if the str can be parsed as a double
	std::istringstream doubleStream(str);
	double doubleValue;
	if ((doubleStream >> doubleValue) && (doubleStream.eof())) {
		return DOUBLE;
	}
	else if (str == "-inf" || str == "+inf" || str =="inf" || str == "nan")
		return DOUBLE;
	return UNKNOWN;
}

const std::string floatSuffix(float value) {

	return ((std::fabs(value - std::floor(value)) < 0.000001) == 1 ?  ".0f" :"f");
}

const std::string doubleSuffix(double value) {
	return ((std::fabs(value - std::floor(value)) < 0.000001) == 1 ?  ".0" :"");
}
void convertChar(const std::string &str)
{
	char charValue = str[0];
	if (std::isprint(charValue)) {
		std::cout << "Char: " << charValue << std::endl;
	} else {
		std::cout << "Char: " << "Non printable" << std::endl;
	}
	std::cout << "Int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "Float: " << static_cast<float>(charValue) << floatSuffix(static_cast<float>(charValue)) <<std::endl;
	std::cout << "Double: " << static_cast<double>(charValue) << doubleSuffix(static_cast<double>(charValue)) << std::endl;
}
void convertInt(const std::string &str)
{
	int intValue;
	std::istringstream(str) >> intValue;
	if (std::isprint(static_cast<int>(intValue))) {
		std::cout << "Char: " << static_cast<char>(intValue) << std::endl;
	} else {
		std::cout << "Char: " << "Non printable" << std::endl;
	}
	std::cout << "Int: " << intValue << std::endl;
	std::cout << "Float: " <<static_cast<float>(intValue) << floatSuffix(static_cast<float>(intValue)) <<std::endl;
	std::cout << "Double: " << static_cast<double>(intValue) << doubleSuffix(static_cast<double>(intValue)) << std::endl;
}
void convertFloat(const std::string &str)
{
	float floatValue;
	if (std::istringstream(str) >> floatValue)
	{
		if (floatValue > static_cast<float>(std::numeric_limits<int>::max()))
		{
			std::cout << "Char: " << "Impossible"<< std::endl;
			std::cout << "Int: " << "overflow" << std::endl;
		}
		else if (floatValue < static_cast<float>(std::numeric_limits<int>::min()))
		{
			std::cout << "Char: " << "Impossible"<< std::endl;
			std::cout << "Int: " << "underflow" << std::endl;
		}
		else
		{
			if (std::isprint(static_cast<int>(floatValue))) {
				std::cout << "Char: " << static_cast<char>(floatValue) << std::endl;
			} else {
				std::cout << "Char: " << "Non printable" << std::endl;
			}
			std::cout << "Int: " << static_cast<int>(floatValue) << std::endl;
		}
		std::cout << "Float: " << floatValue << floatSuffix(floatValue) <<std::endl;
		std::cout << "Double: " << static_cast<double>(floatValue) << doubleSuffix(static_cast<double>(floatValue)) << std::endl;
	} else {
		if (str == "-inff")
			floatValue = -std::numeric_limits<float>::infinity();
		 else if (str == "inff" || str == "+inff")
			floatValue = std::numeric_limits<float>::infinity();
		 else if (str == "nanf")
			floatValue = std::numeric_limits<float>::quiet_NaN();

		if (std::isinf(floatValue) || std::isnan(floatValue))
		{
			std::cout << "Char: " << "impossible" << std::endl;
			std::cout << "Int: " << "impossible"  << std::endl;
			std::cout << "Float: " << floatValue <<"f"<<std::endl;
			std::cout << "Double: " << static_cast<double>(floatValue) << std::endl;
		}
	}
}

void convertDouble(const std::string &str)
{
	double doubleValue;

	if (std::istringstream(str) >> doubleValue)
	{
		if (doubleValue > static_cast<double>(std::numeric_limits<int>::max()))
		{
			std::cout << "Char: " << "impossible" << std::endl;
			std::cout << "Int: " << "overflow" << std::endl;
		}
		else if (doubleValue < static_cast<double>(std::numeric_limits<int>::min()))
		{
			std::cout << "Char: " << "impossible" << std::endl;
			std::cout << "Int: " << "underflow" << std::endl;
		}
		else {
			if (std::isprint(static_cast<int>(doubleValue))) {
				std::cout << "Char: " << static_cast<char>(doubleValue) << std::endl;
			} else {
				std::cout << "Char: " << "Non printable" << std::endl;
			}
			std::cout << "Int: " << static_cast<int>(doubleValue) << std::endl;
		}
		std::cout << "Float: " << static_cast<float>(doubleValue) << floatSuffix(static_cast<float>(doubleValue)) <<std::endl;
		std::cout << "Double: " << doubleValue << doubleSuffix(doubleValue) <<std::endl;
	} else {
		if (str == "-inf")
			doubleValue = -std::numeric_limits<double>::infinity();
		 else if (str == "inf" || str == "+inf")
			doubleValue = std::numeric_limits<double>::infinity();
		 else if (str == "nan")
			doubleValue = std::numeric_limits<double>::quiet_NaN();
		if (std::isinf(doubleValue) || std::isnan(doubleValue))
		{
			std::cout << "Char: " << "impossible" << std::endl;
			std::cout << "Int: " << "impossible"  << std::endl;
			std::cout << "Float: " << static_cast<float>(doubleValue) << "f" <<std::endl;
			std::cout << "Double: " << doubleValue << std::endl;
		}
	}
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


