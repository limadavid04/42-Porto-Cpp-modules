#include "iter.hpp"
#include <iostream>

void add_2(char &x)
{
	x++;
}
template <typename T>
void print (T &x)
{
	std::cout << x <<std::endl;
}

template <typename T>
void add_1(T &x)
{
	x++;
}

int main( void ) {
	{
		char arr[3] = {'a', 'b', 'c'};
		::iter<char>(arr, 3, &add_2);
		::iter<char>(arr, 3, &add_1<char>);
		::iter<char>(arr, 3, &print<char>);
	}
	{
		std::cout << "-------------" <<std::endl;
		float arr[3] = {3.0, 42.3, 54.98};
		::iter<float>(arr, 3, &add_1<float>);
		::iter<float>(arr, 3, &print<float>);
	}
}
