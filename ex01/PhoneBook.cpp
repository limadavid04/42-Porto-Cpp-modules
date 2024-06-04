#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <string>
#include <sstream>

PhoneBook::PhoneBook(void): _n_contacts (0), _cur_contact_i(0)  {};

void PhoneBook::addContact(const Contact &new_contact)
{
	_contacts[_cur_contact_i] = new_contact;
	_cur_contact_i = (_cur_contact_i + 1) % MAX_CONTACTS;
	_n_contacts += (_n_contacts < MAX_CONTACTS);
}

std::string intToStr(int num)
{
	std::stringstream ss;
	ss << num;
	std::string str = ss.str();
	return (str);
}

std::string truncate_str(const std::string &str)
{
	if (str.length() > 10) {
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void	printSingleContact(const Contact &contact, int index)
{

	std::cout << std::setw(10) << std::right << truncate_str(intToStr(index)) << "|";
	std::cout << std::setw(10) << std::right << truncate_str(contact.getFirstName()) << "|";
	std::cout << std::setw(10) << std::right << truncate_str(contact.getLastName()) << "|";
	std::cout << std::setw(10) << std::right << truncate_str(contact.getNickName()) << "|" << std::endl;
}

void PhoneBook::printAllContacts() const
{
	int i = 0;
	if (_n_contacts == 0)
	{

		std::cout << "No contacts available" << std::endl;
		return ;
	}
	while (i < _n_contacts)
	{
		printSingleContact(_contacts[i], i);
		i++;
	}
}
