#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <stdint.h>

#include <cstdlib>
#include <ctime>

Base * generate(void) {

	int r = std::rand() % 3;
	switch (r) {
		case 0: return (std::cout << "Generated: A" << std::endl, new A());
		case 1: return (std::cout << "Generated: B" << std::endl, new B());
		case 2: return (std::cout << "Generated: C" << std::endl,new C());
	}
	return NULL;
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not of type A, B or C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception&) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch (std::exception&) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception &)
			{
				std::cout << "Not of type A, B or C" << std::endl;
			}
		}
	};
}

int main()
{
	srand(time(0));
	Base *ptr = generate();
	Base *ptr_2 = generate();
	identify(ptr);
	identify(*ptr);
	identify(ptr_2);
	identify(*ptr_2);

	delete ptr; // Clean up
	delete ptr_2;
	return 0;
}
