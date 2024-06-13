
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include <iostream>

int main()
{
	int N = 10;
	Animal *animals[N];
	std::cout << "***********Constructing*********"<< std::endl << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i <= N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "-------------"<< std::endl;
	}
	std::cout << "***********Deleting*********"<< std::endl << std::endl;
	for (int i = 0; i < N; i++)
	{
		delete animals[i];
		std::cout << "-------------"<< std::endl;

	}
	return 0;
}
