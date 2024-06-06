#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
	public:
		HumanB(Weapon weapon);
		void attack() const;
	private:
		Weapon _weapon;
		std::string _name;
};
#endif
