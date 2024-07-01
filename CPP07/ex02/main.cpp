#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define VALUE 5

void	value_tests()
{
	Array<int> array(VALUE);
	Array<int> empty(array);

	std::cout  << "VALUE AT CONSTRUCTION"  << std::endl;
	std::cout << "array: ";
	array.print();

	srand(time(0));
	for (int i = 0; i < VALUE; i++)
    {
        const int value = rand() % 21;
        array[i] = value;
    }

	std::cout  << "VALUE OF ARRAY"  << std::endl;
	std::cout << "array: ";
	array.print();

	try
	{
		array[0] = 42;

		std::cout  << "VALUE OF ARRAY"  << std::endl;
		std::cout << "array: ";
		array.print();

		// access out of range
		array[VALUE] = 42;

		std::cout  << "VALUE OF ARRAY"  << std::endl;
		std::cout << "array: ";
		array.print();
	}
	catch (std::exception &e)
	{
		std::cout  << e.what()  << std::endl;
	}

}

void	string_tests()
{
    Array<std::string> array(VALUE);

	std::cout  << "VALUE AT CONSTRUCTION"  << std::endl;
	std::cout << "array: ";
	array.print();

	for (int i = 0; i < VALUE; i++)
    {
        std::string value = "Hello";
        array[i] = value;
    }

	std::cout  << "VALUE OF ARRAY"  << std::endl;
	std::cout << "array: ";
	array.print();

	try
	{
		array[0] = "Bye";

		std::cout  << "VALUE OF ARRAY"  << std::endl;
		std::cout << "array: ";
		array.print();

		array[VALUE] = "Bye";

		std::cout  << "VALUE OF ARRAY"  << std::endl;
		std::cout << "array: ";
		array.print();
	}
	catch (std::exception &e)
	{
		std::cout  << e.what()  << std::endl;
	}

}

void	copy_tests()
{
	Array<int> array(VALUE);

	srand(time(0));
	for (int i = 0; i < VALUE; i++)
    {
        const int value = rand() % 21;
        array[i] = value;
    }

	Array<int> empty(array);

	std::cout  << "COPY CONSTRUCTOR TEST"  << std::endl;
	std::cout << "array: ";
	array.print();
	std::cout << "empty: ";
	empty.print();
	std::cout << std::endl;

	std::cout  << "COPY ASSIGNMENT OVERLOADER TEST"  << std::endl;
	Array<int> tmp;
	tmp = array;
	std::cout << "tmp: ";
	tmp.print();
}

int main()
{
	std::cout << std::endl

			  << "VALUE TESTS"

			  << std::endl
			  << std::endl;
	value_tests();

	std::cout << std::endl

			  << "STRING TESTS"

			  << std::endl
			  << std::endl;
	string_tests();

	std::cout << std::endl

			  << "COPY TESTS"

			  << std::endl
			  << std::endl;
	copy_tests();

	std::cout << std::endl;
	return 0;
}
