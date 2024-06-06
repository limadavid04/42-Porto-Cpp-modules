#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int	n = 9;

	horde = zombieHorde(n, "david");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}
