#include <cstdlib>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
	this->saved = 0;
	this->max = 8;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook Destructor called" << std::endl;
}

Contact	PhoneBook::GetFirstEmptyContact()
{
	if (this->saved == this->max)
		this->saved = 0;
	return this->Contacts[this->saved];
}

void	PhoneBook::AddContact(Contact &contact)
{
	if (this->saved == this->max)
		this->saved = 0;
	this->Contacts[this->saved++] = contact;
}


int	PhoneBook::GetCurrentIndex() {
	if (this->Contacts[saved].GetFirstName().empty() || this->saved == this->max)
		return this->saved - 1;
	return this->saved;
}

Contact	*PhoneBook::GetContacts() { return this->Contacts; }

int	PhoneBook::GetMax() { return this->max; }