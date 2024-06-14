#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {

	public:
		Cure();
		Cure(Cure const & cpy);
		~Cure();
		Cure const & operator=(Cure const &src);

		std::string const & getType() const;
		AMateria* clone() const = 0;
		void use(ICharacter& target);
};
#endif
