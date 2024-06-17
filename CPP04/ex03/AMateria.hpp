#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
class ICharacter;
class AMateria
{
	public:
		AMateria();
		AMateria(AMateria const & cpy);
		virtual ~AMateria();
		AMateria const & operator=(AMateria const &src);

		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
	protected:
		std::string _type;
};
#endif
