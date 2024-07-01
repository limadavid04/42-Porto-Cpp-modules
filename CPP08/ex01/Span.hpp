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
