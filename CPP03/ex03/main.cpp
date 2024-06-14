#include "DiamondTrap.hpp"
#include <iostream>

int main() {

	DiamondTrap	Trap("Jonny");
	DiamondTrap Trap_3;

	// Trap_3 = Trap;

	// cpy constructor test;
	Trap_3.attack("Jack"); // ScavTrap_3 member function
	Trap_3.takeDamage(5);
	Trap_3.beRepaired(5);
	Trap_3.guardGate(); // ScavTrap_3 member function
	Trap_3.highFivesGuys(); // FragTrap_3 member function
	Trap_3.whoAmI();

	Trap.attack("Jack"); // ScavTrap member function
	Trap.takeDamage(5);
	Trap.beRepaired(5);
	Trap.guardGate(); // ScavTrap member function
	Trap.highFivesGuys(); // FragTrap member function
	Trap.whoAmI();
}

