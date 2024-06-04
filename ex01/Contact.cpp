#include "Contact.hpp"


// static bool Valid_field()
bool Contact::setFirstName(const std::string &first_name)
{
	// if ()
	_first_name = first_name;
	return (true);
}

bool Contact::setLastName(const std::string &last_name)
{
	_last_name = last_name;
	return (true);
}

bool Contact::setNickName(const std::string &nickname)
{
	_nickname = nickname;
	return (true);
}

bool Contact::setPhoneNumber(const std::string &phone_number)
{
	_phone_number = phone_number;
	return (true);
}

bool Contact::setDarkestSecret(const std::string &darkest_secret)
{
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
