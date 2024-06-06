#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "str_ptr address: " << &str_ptr << std::endl;
	std::cout << "str_ref address: " << &str_ref << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "str_ptr value: " << *str_ptr << std::endl;
	std::cout << "str_ref value: " << str_ref << std::endl;

}
