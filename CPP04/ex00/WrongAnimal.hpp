#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpy);
		WrongAnimal & operator=( const WrongAnimal & src);
		virtual ~WrongAnimal();

		const std::string & getType() const ;
		void makeSound() const;
	protected:
		std::string type;
};
#endif
