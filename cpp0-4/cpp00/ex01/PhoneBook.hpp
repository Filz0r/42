#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	private:
		int			max;
		int			saved;
		Contact		Contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		int 	GetCurrentIndex();
		int 	GetMax();
		void 	AddContact(Contact &data);
		Contact *GetContacts();
		Contact	GetFirstEmptyContact();
};

#endif //PHONEBOOK_H
