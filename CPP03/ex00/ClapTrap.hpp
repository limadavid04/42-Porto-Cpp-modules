#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &cpy);
		ClapTrap & operator=( const ClapTrap & src);
		~ClapTrap();

		ClapTrap(const std::string &name);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
};
#endif
