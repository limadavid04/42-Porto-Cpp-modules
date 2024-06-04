/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneApp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:06:04 by dlima             #+#    #+#             */
/*   Updated: 2024/06/04 12:21:38 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>


static std::string trim(const std::string &str)
{
	std::string trimmed = str;
	trimmed.erase(0, str.find_first_not_of("\t\n\v\f\r ")); // left trim
	trimmed.erase(str.find_last_not_of("\t\n\v\f\r ") + 1); // right trim
	return (trimmed);
}

bool strIsAlpha (std::string str)
{
	std::string::iterator i;
	// int	w_count = 0;

	for (i = str.begin(); i < str.end(); i++)
	{
		if (!isalpha(*i))
			return false;
		// w_count += isspace(*i) > 0 ? 1 : 0;
	}
	return true;
	// return (w_count == str.length() ? false : true);
}
bool strIsDigit(std::string str)
{
	std::string::iterator i;
	bool isSpaceAllowed = true; // flag to track if space is allowed between digits
	for (i = str.begin(); i < str.end(); i++)
	{
		if (isdigit(*i))
			isSpaceAllowed = true; // reset the flag if a digit is encountered
		else if (isspace(*i))
		{
			if (!isSpaceAllowed)
				return false; // return false if space is not allowed between digits
			isSpaceAllowed = false; // set the flag to false after encountering a space
		}
		else
			return false; // return false if a non-digit and non-space character is encountered
	}
	return true;
}

void	valid_command_prompt(void)
{
	std::cout << "Please enter one of the following commands: " << std::endl;
	std::cout << "[ADD] -> to add a new contact" << std::endl;
	std::cout << "[SEARCH] -> to display the info of a contact" << std::endl;
	std::cout << "[EXIT] -> to exit the program" << std::endl;
}

void	invalid_command_prompt(const std::string &prompt)
{
	std::cout << "Invalid " << prompt << ", try again..." <<std::endl;
	if (prompt == COMMAND)
		valid_command_prompt();
}

std::string read_input(const std::string &prompt)
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
bool create_new_contact(void)
{
	Contact new_contact;

	std::cout << "Please introduce your new contact info" << std::endl;
	while (!new_contact.setFirstName(read_input(FIRST_NAME)))
	{
		if (std::cin.eof())
			return (false);
		invalid_command_prompt(FIRST_NAME);
	}
	while (!new_contact.setLastName(read_input(LAST_NAME)))
	{
		if (std::cin.eof())
			return (false);
		invalid_command_prompt(LAST_NAME);
	}
	while (!new_contact.setNickName(read_input(NICKNAME)))
	{
		if (std::cin.eof())
			return (false);
		invalid_command_prompt(NICKNAME);
	}
	while (!new_contact.setPhoneNumber(read_input(PHONE_NBR)))
	{
		if (std::cin.eof())
			return (false);
		invalid_command_prompt(PHONE_NBR);
	}
	while (!new_contact.setDarkestSecret(read_input(DARKEST_SECRET)))
	{
		if (std::cin.eof())
			return (false);
		invalid_command_prompt(DARKEST_SECRET);
	}
	new_contact.printContact();
	return true;
}
void	process_input(void)
{
	std::string new_line;

	while(std::getline(std::cin, new_line))
	{
		if (new_line == "ADD")
		{
			create_new_contact();
		}
		else if (new_line == "SEARCH")
			std::cout << "searching..." << std::endl;
		else if (new_line == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		else
			invalid_command_prompt(COMMAND);
	}
}
int main (int argc, char **argv)
{
	// PhoneBook pBook;

	(void)argc;
	(void)argv;
	std::cout << "WELCOME to Phone Book" << std::endl;
	valid_command_prompt();
	process_input();
	return (0);
}
