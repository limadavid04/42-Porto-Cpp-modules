#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

	public:
		// Contact(void);
		// ~Contact(void);
		bool setFirstName(const std::string &first_name);
		bool setLastName(const std::string &last_name);
		bool setNickName(const std::string &nickname);
		bool setPhoneNumber(const std::string &phone_number);
		bool setDarkestSecret(const std::string &darkest_secret);
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickName() const;
		const std::string& getPhoneNumber() const;
		const std::string& getDarkestSecret() const;
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif
