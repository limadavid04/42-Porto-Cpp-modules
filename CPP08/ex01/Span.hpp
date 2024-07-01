#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iterator>
#include <stdexcept>
#include <iostream>
class Span {

	private:
		std::multiset<int> _s;
		unsigned int _N;
	public:
		Span(): _s(), _N(0) {};
		Span(const Span &cpy) : _s(cpy._s), _N(cpy._N) {};
		Span & operator=(const Span &src) {
			if (this != &src)
			{
				_s = src._s;
				_N = src._N;
			}
			return (*this);
		}
		~Span() {};
		Span(unsigned int N);
		void addNumber(int value);
		class SetFullException : public std::exception {
			public :
				virtual const char * what() const throw ();
		};
		class SetTooSmallException : public std::exception {
			public :
				virtual const char * what() const throw ();
		};
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) + _s.size() > _N)
				throw SetFullException();
			_s.insert(begin, end);
		};
		void print() const;
};
#endif
