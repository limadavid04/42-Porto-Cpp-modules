#include "Contact.hpp"
#include <iostream>
#include <string>

void Contact::printContact() const
{
	std::cout << "First Name: " << _first_name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest Secret " << _darkest_secret << std::endl;

}
bool Contact::setFirstName(const std::string &first_name)
{
	if (first_name.empty())
		return (false);
	_first_name = first_name;
	return (true);
}

bool Contact::setLastName(const std::string &last_name)
{
	if (last_name.empty())
		return (false);
	_last_name = last_name;
	return (true);
}

bool Contact::setNickName(const std::string &nickname)
{
	if (nickname.empty())
		return (false);
	_nickname = nickname;
	return (true);
}

bool Contact::setPhoneNumber(const std::string &phone_number)
{
	if (phone_number.empty())
		return (false);
	_phone_number = phone_number;
	return (true);
}

bool Contact::setDarkestSecret(const std::string &darkest_secret)
{
	if (darkest_secret.empty())
		return (false);
	_darkest_secret = darkest_secret;
	return (true);
}

const std::string& Contact::getFirstName() const {
	return _first_name;
}

const std::string& Contact::getLastName() const {
	return _last_name;
}

const std::string& Contact::getNickName() const {
	return _nickname;
}

const std::string& Contact::getPhoneNumber() const {
	return _phone_number;
}

const std::string& Contact::getDarkestSecret() const {
	return _darkest_secret;
}
