#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>


void	deep_copy()
{
	Character *bob = new Character("bob");
	Character *me = new Character(*bob);

	// The address of 1 and 2 should be different
	std::cout << "---------------------------" << std::endl;
	std::cout << "Bob = " << &bob << std::endl;
	std::cout << "me = " << &me << std::endl;
	std::cout << "---------------------------" << std::endl;

	delete bob;
	delete me;
}

int main_tests()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	AMateria* tmp2;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

int main()
{
	std::cout << std::endl << "\033[1;31m"
			  << "MAIN TESTS"
			  << "\033[0m" << std::endl << std::endl;
	main_tests();

	std::cout << std::endl << "\033[1;31m"
			  << "DEEP COPY TESTS"
			  << "\033[0m" << std::endl << std::endl;
	deep_copy();

	std::cout << std::endl;
	return 0;
}
