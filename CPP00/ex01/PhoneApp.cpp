/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneApp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:06:04 by dlima             #+#    #+#             */
/*   Updated: 2024/06/06 10:24:35 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

static std::string trim(const std::string &str)
{
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of("\t\n\v\f\r "));
	trimmed.erase(trimmed.find_last_not_of("\t\n\v\f\r ") + 1);
	return (trimmed);
}

bool strIsAlpha (std::string str)
{
	std::string::iterator i;
	bool isSpaceAllowed = true;
	for (i = str.begin(); i < str.end(); i++)
	{
		if (isalpha(*i))
			isSpaceAllowed = true;
		else if (isspace(*i))
		{
			if (!isSpaceAllowed)
				return false;
			isSpaceAllowed = false;
		}
		else
			return false;
	}
	return true;
}
bool strIsDigit(std::string &str)
{
	std::string::iterator i;
	bool isSpaceAllowed = true;
	for (i = str.begin(); i < str.end(); i++)
	{
		if (isdigit(*i))
			isSpaceAllowed = true;
		else if (isspace(*i))
		{
			if (!isSpaceAllowed)
				return false;
			isSpaceAllowed = false;
		}
		else
			return false;
	}
	return true;
}

void	valid_command_prompt(void)
{
	std::cout << "Please enter one of the following commands: " << std::endl;
	std::cout << "[ADD] -> to add a new contact" << std::endl;
	std::cout << "[SEARCH] -> to display the info of a contact" << std::endl;
	std::cout << "[EXIT] -> to exit the program" << std::endl << std::endl;
	std::cout << "Please enter a command: ";
}

void	invalid_command_prompt(const std::string &prompt)
{
	std::string str;
	std::cout << "Invalid " << prompt << ", try again..." << std::endl;
}

const std::string read_input(const std::string &prompt)
{
	std::string new_line;

	std::cout << prompt << ": ";
	std::getline(std::cin, new_line);
	if (std::cin.eof())
		return (std::string());
	if (prompt == FIRST_NAME || prompt == LAST_NAME)
		return (strIsAlpha(new_line) ? trim(new_line): std::string());
	if (prompt == PHONE_NBR)
		return (strIsDigit(new_line) ? trim(new_line): std::string());
	return trim(new_line);
}

void create_new_contact(PhoneBook &pBook)
{
	Contact new_contact;

	std::cout << std::endl << "Please introduce your new contact info" << std::endl << std::endl;
	while (!new_contact.setFirstName(read_input(FIRST_NAME)))
	{
		if (std::cin.eof())
			return ;
		invalid_command_prompt(FIRST_NAME);
	}
	while (!new_contact.setLastName(read_input(LAST_NAME)))
	{
		if (std::cin.eof())
			return ;
		invalid_command_prompt(LAST_NAME);
	}
	while (!new_contact.setNickName(read_input(NICKNAME)))
	{
		if (std::cin.eof())
			return ;
		invalid_command_prompt(NICKNAME);
	}
	while (!new_contact.setPhoneNumber(read_input(PHONE_NBR)))
	{
		if (std::cin.eof())
			return ;
		invalid_command_prompt(PHONE_NBR);
	}
	while (!new_contact.setDarkestSecret(read_input(DARKEST_SECRET)))
	{
		if (std::cin.eof())
			return ;
		invalid_command_prompt(DARKEST_SECRET);
	}
	if (std::cin.eof())
		return ;
	pBook.addContact(new_contact);
}

void	process_input(void)
{
	std::string new_line;
	PhoneBook pBook;

	do {
		system("clear");
		valid_command_prompt();
		std::getline(std::cin, new_line);
		if (new_line == "ADD")
			create_new_contact(pBook);
		else if (new_line == "SEARCH")
			pBook.searchContacts();
		else if (new_line == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		else if (!std::cin.eof())
		{
			invalid_command_prompt(COMMAND);
			usleep(700000);
		}
	} while (!std::cin.eof());
}

int main ()
{
	std::cout << "WELCOME to Phone Book" << std::endl << std::endl;
	process_input();
	return (0);
}
