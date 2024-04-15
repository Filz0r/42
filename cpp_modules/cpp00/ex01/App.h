#ifndef APP_H
# define APP_H

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

int		GetIndex();
int 	isValidNumber(const std::string &input);
int		PrintMenu(PhoneBook &data);
int 	SearchContact(PhoneBook &data);
int		AddNewContact(PhoneBook &data);
void	PrintPrompt(int position);
void	PhonebookApp(PhoneBook &data);
bool	IsWhitespace(const std::string &str);
bool	UpdateEmptyContact(Contact &empty, const std::string &input ,int position);
std::string		removeWhitespace(const std::string &str);

#endif //APP_H
