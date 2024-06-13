
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
	std::cout << "************----Constructing Cats-----*********"<< std::endl;
	Cat *cat = new Cat();
	Cat *cat_2 = new Cat(*cat);
	std::cout << "************---------*********"<< std::endl << std::endl;

	std::cout << "************----Deleting Cats----*********"<< std::endl;
	delete cat;
	delete cat_2;
	std::cout << "************---------*********"<< std::endl << std::endl;

	std::cout << "************----Constructing Dogs-----*********"<< std::endl;
	Dog *dog = new Dog();
	Dog *dog_2 = new Dog(*dog);
	std::cout << "************---------*********"<< std::endl << std::endl;

	std::cout << "************----Deleting Dogs----*********"<< std::endl;
	delete dog;
	delete dog_2;
	std::cout << "************---------*********"<< std::endl << std::endl;
}
