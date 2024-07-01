#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

	public:
		MutantStack() : std::stack<T, Container>() {};
		//  using iterator = typename Container::iterator;
		// using const_iterator = typename Container::const_iterator;
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}

};
#endif
