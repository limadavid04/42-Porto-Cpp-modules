#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat & operator=( const Cat & src);
		~Cat();
		void makeSound() const;
	private:
		Brain * _brain;
};
#endif
