#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {

	public:
		Ice();
		Ice(Ice const & cpy);
		~Ice();
		Ice const & operator=(Ice const &src);

		std::string const & getType() const;
		AMateria* clone() const = 0;
		void use(ICharacter& target);
};
#endif
