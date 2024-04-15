#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
//	std::cout << "PhoneBook Constructor called" << std::endl;
	this->saved = 0;
}

PhoneBook::~PhoneBook() {
//	std::cout << "PhoneBook Destructor called" << std::endl;
}

Contact	PhoneBook::GetFirstEmptyContact()
{
	return this->Contacts[this->saved];
}

void	PhoneBook::AddContact(Contact &contact)
{
	this->Contacts[saved] = contact;
	this->saved = (this->saved + 1) % max;
}


int	PhoneBook::GetCurrentIndex() const {
	return this->saved;
}

Contact	*PhoneBook::GetContacts() { return this->Contacts; }

int	PhoneBook::GetMax() { return max; }