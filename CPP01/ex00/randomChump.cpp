#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie z = Zombie();
	z.setName(name);
	z.announce();
}
