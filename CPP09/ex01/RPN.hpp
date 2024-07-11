#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int> _stack;
		RPN(const RPN &cpy);
		RPN & operator=(const RPN & src);
	public:
		RPN();
		~RPN();
		int convert(std::string &str);
		void execute_op(std::string & op);
		void push_digit(std::string & digit);

};
#endif
