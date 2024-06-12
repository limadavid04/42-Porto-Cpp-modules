#include "ScavTrap.hpp"
#include <iostream>

int main() {
	// Create a ScavTrap with default name
	ScavTrap defaultTrap("Scav_1");
	ScavTrap Trap_1;
	Trap_1.attack("ola");
	defaultTrap.attack("target1");
	defaultTrap.takeDamage(5);
	defaultTrap.beRepaired(3);
	defaultTrap.guardGate();
	// Test that ScavTrap can't attack or repair itself when it has no energy points
	defaultTrap.takeDamage(10);
	defaultTrap.attack("target1"); // Should not be able to attack
	defaultTrap.beRepaired(3); // Should not be able to repair

	std::cout << "-----------------" <<std::endl;

	// Create a ScavTrap with a custom name
	ScavTrap customTrap("scav_2");

	customTrap.attack("target2");
	customTrap.takeDamage(7);
	customTrap.beRepaired(4);

	// Test that ScavTrap can't attack or repair itself when it has no energy points
	for (int i = 0; i < 9; i++)
		customTrap.attack("target2"); // drain energy
	customTrap.beRepaired(4); // Should not be able to repair

	// Test that ScavTrap can't attack or repair itself when it has no hit points
	customTrap.takeDamage(10);
	customTrap.attack("target2"); // Should not be able to attack
	customTrap.beRepaired(4); // Should not be able to repair

	return 0;
}
