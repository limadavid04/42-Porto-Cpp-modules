#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN();
		// RPN(const RPN &cpy);
		// RPN & operator=(const RPN & src);
		// ~RPN();
		// RPN(const std::string & input);
		int convert(std::string &str);
		void execute_op(std::string & op);
		void push_digit(std::string & digit);

};
#endif
