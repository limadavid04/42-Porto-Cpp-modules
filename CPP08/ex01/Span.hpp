#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iterator>
#include <stdexcept>
class Span {

	private:
		std::set<int> _s;
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
		template <typename Container>
		void addNumberBulk(typename Container::iterator begin, typename Container::iterator end)
		{
			typename Container::iterator cur = begin;
			while (cur != end)
			{
				addNumber(*cur);
				cur++;
			}
		};
		void print() const;
};
#endif
