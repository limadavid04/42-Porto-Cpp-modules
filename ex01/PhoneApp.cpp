/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneApp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:06:04 by dlima             #+#    #+#             */
/*   Updated: 2024/06/03 18:52:54 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	valid_command_prompt(void)
{
	std::cout << "Please enter one of the following commands: " << std::endl;
	std::cout << "[ADD] -> to add a new contact" << std::endl;
	std::cout << "[SEARCH] -> to display the info of a contact" << std::endl;
	std::cout << "[EXIT] -> to exit the program" << std::endl;
}

void	wrong_command_prompt(void)
{
	std::cout << "Invalid Command!" << std::endl;
	valid_command_prompt();
}


bool create_new_contact(void)
{
	std::string new_line;
	Contact new_contact;

	std::cout << "Please introduce your new contact info" << std::endl;
	std::cout << "First Name: ";
	std::getline(std::cin, new_line);
	while (!new_contact.setFirstName(new_line))
	{
		if (std::cin.eof())
			return (false);
		wrong_command_prompt();
		std::cout << "First Name: ";
		std::getline(std::cin, new_line);
	}
	// std::cout << new_contact.getFirstName() << std::endl;
	std::cout << "Last Name: ";
	std::getline(std::cin, new_line);
	while (!new_contact.setLastName(new_line))
	{
		if (std::cin.eof())
			return (false);
		wrong_command_prompt();
		std::cout << "Last Name: ";
		std::getline(std::cin, new_line);
	}
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
			wrong_command_prompt();
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
