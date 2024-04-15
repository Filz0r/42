#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		Contact();
		~Contact();

		int 	ClearFields();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetPhoneNumber();
		std::string GetNickname();
		std::string GetDarkestSecret();
		void SetFirstName(const std::string &FirstName);
		void SetLastName(const std::string &LastName);
		void SetPhoneNumber(const std::string &PhoneNumber);
		void SetNickname(const std::string &Nickname);
		void SetDarkestSecret(const std::string &DarkestSecret);
};

#endif //CONTACT_H
