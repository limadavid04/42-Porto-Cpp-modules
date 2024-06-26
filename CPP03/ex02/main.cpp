#include "FragTrap.hpp"
#include <iostream>

int main() {
	// Create a FragTrap with default name
	FragTrap defaultTrap("FRAG_1");
	FragTrap Trap;
	Trap.beRepaired(10);
	defaultTrap.attack("target1");
	defaultTrap.takeDamage(5);
	defaultTrap.beRepaired(3);
	defaultTrap.highFivesGuys();
	// Test that FragTrap can't attack or repair itself when it has no energy points
	defaultTrap.takeDamage(10);
	defaultTrap.attack("target1"); // Should not be able to attack
	defaultTrap.beRepaired(3); // Should not be able to repair

	std::cout << "-----------------" <<std::endl;

	// Create a FragTrap with a custom name
	FragTrap customTrap("FRAG_2");

	customTrap.attack("target2");
	customTrap.takeDamage(7);
	customTrap.beRepaired(4);

	// Test that FragTrap can't attack or repair itself when it has no energy points
	for (int i = 0; i < 9; i++)
		customTrap.attack("target2"); // drain energy
	customTrap.beRepaired(4); // Should not be able to repair

	// Test that FragTrap can't attack or repair itself when it has no hit points
	customTrap.takeDamage(10);
	customTrap.attack("target2"); // Should not be able to attack
	customTrap.beRepaired(4); // Should not be able to repair

	return 0;
}
