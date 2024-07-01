#include "Span.hpp"
#include <iterator>
#include <limits>
#include <set>
#include <iostream>
Span::Span(unsigned int N) : _s(), _N(N) {};
unsigned int Span::shortestSpan() const {

	if (_s.size()< 2)
		throw Span::SetTooSmallException();
	std::multiset<int>::iterator it = _s.begin();
	std::multiset<int>::iterator it_2 = ++_s.begin();

	unsigned int min_span = std::numeric_limits<unsigned int>::max();
	unsigned int cur_span;
	while (it_2 != _s.end())
	{
		cur_span = *it_2 - *it;
		min_span = (cur_span < min_span) ? cur_span : min_span;
		it++;
		it_2++;
	}
	return (min_span);
}

unsigned int Span::longestSpan() const {
	if (_s.size() < 2)
		throw Span::SetTooSmallException();
	std::multiset<int>::iterator it = _s.begin();
	std::multiset<int>::iterator it_2 = --_s.end();
	return (*it_2 - *it);
}
const char* Span::SetFullException::what() const throw() {
	return ("Set is full");
}
const char* Span::SetTooSmallException::what() const throw() {
	return ("Set has not enough elements to determine span");
}
void Span::addNumber(int value) {
	if (_s.size() == _N)
		throw Span::SetFullException();
	_s.insert(value);
}
void Span::print() const {
	std::multiset<int>::iterator it = _s.begin();
	while (it !=_s.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}
