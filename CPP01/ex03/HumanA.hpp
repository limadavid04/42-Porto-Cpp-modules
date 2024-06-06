#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
	public:
		HumanA(Weapon weapon);
		void attack() const;
	private:
		Weapon _weapon;
		std::string _name;
};
#endif
