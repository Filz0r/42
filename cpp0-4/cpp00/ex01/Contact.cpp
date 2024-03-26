#include "Contact.hpp"

Contact::Contact() { std::cout << "New Empty Contact Created" << std::endl; }
Contact::~Contact() { std::cout << "Deleted Contact " << this->FirstName << std::endl; }

std::string Contact::GetFirstName() { return this->FirstName; }
void Contact::SetFirstName(std::string name) { this->FirstName = name; }

std::string Contact::GetLastName() { return this->LastName; }
void Contact::SetLastName(std::string name) { this->LastName = name; }

std::string Contact::GetNickname() { return this->Nickname; }
void Contact::SetNickname(std::string name) { this->Nickname = name; }

std::string Contact::GetPhoneNumber() { return this->PhoneNumber; }
void Contact::SetPhoneNumber(std::string number) { this->PhoneNumber = number; }

std::string Contact::GetDarkestSecret() { return this->DarkestSecret; }
void Contact::SetDarkestSecret(std::string secret) { this->DarkestSecret = secret; }

int 	Contact::ClearFields() {
	FirstName.clear();
	LastName.clear();
	Nickname.clear();
	DarkestSecret.clear();
	PhoneNumber.clear();
	return 0;
}
