#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
class Animal {
	public:
		Animal();
		Animal(const Animal &cpy);
		Animal & operator=( const Animal & src);
		virtual ~Animal();

		const std::string & getType() const ;
		virtual void makeSound() const = 0;
	protected:
		std::string type;
};
#endif
