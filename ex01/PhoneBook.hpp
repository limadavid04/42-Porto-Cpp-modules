#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#ifndef MAX_CONTACTS
#define MAX_CONTACTS 8
#endif

class PhoneBook {

	public:
		PhoneBook(void);
		void	addContact(const Contact &new_contact);
	private:
		Contact _contacts[MAX_CONTACTS];
		int	_n_contacts;
		int	_cur_contact_i;
};

#endif
