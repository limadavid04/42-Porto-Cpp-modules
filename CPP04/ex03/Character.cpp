
#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
	Character::Character() : _name("default")
	{
		// std::cout <<"Character default constructor called" <<std::endl;
		for(int i = 0; i < 4; i++)
			_inventory[i] = NULL;
	}
	Character::Character(Character const &cpy)
	{
		// std::cout <<"Character copy constructor called" <<std::endl;
		for(int i = 0; i < 4; i++)
			_inventory[i] = NULL;
		*this = cpy;
	}
	const Character & Character::operator=(const Character &src)
	{
		if (this != &src)
		{
			_name = src.getName();
			for (int i = 0; i < 4; i++)
			{
				delete _inventory[i];
				_inventory[i] = NULL;
				equip(src._inventory[i]);
			}
		}
		return *this;
	}
	Character::~Character()
	{
		// std::cout <<"Character destructor called" <<std::endl;
		for (int i = 0; i < 4; i++)
			delete _inventory[i];
	}
	Character::Character(std::string const &name) : _name(name)
	{
		// std::cout <<"Character param constructor called" <<std::endl;
		for(int i = 0; i < 4; i++)
			_inventory[i] = NULL;
	}
	std::string const & Character::getName() const
	{
		return _name;
	}
	void Character::equip(AMateria* m)
	{
		int i = 0;
		if (m == NULL)
			return ;
		while (i < 4 && _inventory[i] != NULL)
			i++;
		if (i < 4)
			_inventory[i] = m;
	}

	void Character::unequip(int idx)
	{
		if (idx < 4)
			_inventory[idx] = NULL;
	}
	
	void Character::use(int idx, ICharacter& target)
	{
		if (!(idx < 4) || _inventory[idx] != NULL)
			_inventory[idx]->use(target);
	}
