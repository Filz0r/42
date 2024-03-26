#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::GetFirstName() { return this->FirstName; }
void Contact::SetFirstName(const std::string &name) { this->FirstName = name; }

std::string Contact::GetLastName() { return this->LastName; }
void Contact::SetLastName(const std::string &name) { this->LastName = name; }

std::string Contact::GetNickname() { return this->Nickname; }
void Contact::SetNickname(const std::string &name) { this->Nickname = name; }

std::string Contact::GetPhoneNumber() { return this->PhoneNumber; }
void Contact::SetPhoneNumber(const std::string &number) { this->PhoneNumber = number; }

std::string Contact::GetDarkestSecret() { return this->DarkestSecret; }
void Contact::SetDarkestSecret(const std::string &secret) { this->DarkestSecret = secret; }

int 	Contact::ClearFields() {
	FirstName.clear();
	LastName.clear();
	Nickname.clear();
	DarkestSecret.clear();
	PhoneNumber.clear();
	return 0;
}
