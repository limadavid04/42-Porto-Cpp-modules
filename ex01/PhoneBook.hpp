#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#ifndef MAX_CONTACTS
#define MAX_CONTACTS 8
#endif
#ifndef FIRST_NAME
#define FIRST_NAME "First Name"
#endif
#ifndef LAST_NAME
#define LAST_NAME "Last Name"
#endif
#ifndef NICKNAME
#define NICKNAME "Nickname"
#endif
#ifndef PHONE_NBR
#define PHONE_NBR "Phone number"
#endif
#ifndef COMMAND
#define COMMAND "Command"
#endif
#ifndef DARKEST_SECRET
#define DARKEST_SECRET "DARKEST_SECRET"
#endif

std::string truncate_str(const std::string &str);

class PhoneBook {

	public:
		PhoneBook(void);
		void	addContact(const Contact &new_contact);
		void	searchContacts() const;
	private:
		Contact _contacts[MAX_CONTACTS];
		int	_n_contacts;
		int	_cur_contact_i;

};

#endif
