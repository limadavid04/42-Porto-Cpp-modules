#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
	public:
		Character();
		Character(Character const &cpy);
		const Character & operator=(const Character &src);
		~Character();

		Character(std::string const &name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria * _inventory[4];
};
#endif
