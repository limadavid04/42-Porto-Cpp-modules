#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat & operator=( const Cat & src);
		~Cat();
		void makeSound() const;
};
#endif
