#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
RPN::RPN() : _stack() {};
RPN::RPN(const RPN &cpy) {
	(void)cpy;
};
RPN & RPN::operator=(const RPN & src) {
	(void)src;
	return *this;
};
RPN::~RPN() {};
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}
void RPN::execute_op(std::string & op) {
	rtrim(op);
	int	a, b;

	if (!_stack.empty() && _stack.size() >= 2) {
		b = _stack.top();
		_stack.pop();
		a = _stack.top();
		_stack.pop();
	}
	else
		throw std::runtime_error("Error: Cannot perform operation because stack has less than 2 elements");
	if (op == "+")
		_stack.push(a + b);
	else if (op == "-")
		_stack.push(a - b);
	else if (op == "*")
		_stack.push(a * b);
	else if (op == "/")
		_stack.push(a / b);
	else
		throw std::runtime_error("Error: Unknown operation token");
}
void RPN::push_digit(std::string & digit) {
	rtrim(digit);
	std::istringstream intStream(digit);
	int intValue;
	if ((intStream >> intValue) && (intStream.eof()) && (intValue >= 0 && intValue < 10))
		_stack.push(intValue);
	else
		throw std::runtime_error("Error: Invalid Digit");
}

int RPN::convert(std::string &str)
{
	std::istringstream ss(str);
	if (ss.eof())
		throw std::runtime_error("Error");
	while (!ss.eof())
	{
		std::string token;
		ss >> token;
		if (token.size() == 1 && !(token[0] >= '0' && token [0] <= '9'))
			execute_op(token);
		else
			push_digit(token);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Incorrect expression");
	return _stack.top();
}


