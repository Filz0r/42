#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	private:
		static const int	max = 8;
		int			saved;
		Contact		Contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		int 	GetCurrentIndex() const;
		static int 	GetMax() ;
		void 	AddContact(Contact &data);
		Contact *GetContacts();
		Contact	GetFirstEmptyContact();
};

#endif //PHONEBOOK_H
