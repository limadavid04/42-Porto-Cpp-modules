#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog & operator=( const Dog & src);
		~Dog();
		void makeSound() const;
};
#endif
