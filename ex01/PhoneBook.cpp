#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): _n_contacts (0), _cur_contact_i(0)  {};

void PhoneBook::addContact(const Contact &new_contact)
{
	_contacts[_cur_contact_i] = new_contact;
	_cur_contact_i = (_cur_contact_i + 1) % MAX_CONTACTS;
	_n_contacts += (_n_contacts < MAX_CONTACTS);

}
