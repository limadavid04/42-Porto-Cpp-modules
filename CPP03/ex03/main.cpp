#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap	Trap("Jonny");
	DiamondTrap Trap_3;

	// Trap_3 = Trap;
	//cpy constructor test;
	// DiamondTrap Trap_2(Trap);
	// Trap_2.attack("Jack"); // ScavTrap_2 member function
	// Trap_2.takeDamage(5);
	// Trap_2.beRepaired(5);
	// Trap_2.guardGate(); // ScavTrap_2 member function
	// Trap_2.highFivesGuys(); // FragTrap_2 member function
	// Trap_2.whoAmI();

	Trap.attack("Jack"); // ScavTrap member function
	Trap.takeDamage(5);
	Trap.beRepaired(5);
	Trap.guardGate(); // ScavTrap member function
	Trap.highFivesGuys(); // FragTrap member function
	Trap.whoAmI();
}

