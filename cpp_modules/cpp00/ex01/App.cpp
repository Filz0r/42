#include <App.h>

// Main loop where the App gets stuck until EXIT is called or an error occurs
void	PhonebookApp(PhoneBook &data)
{
	std::cout << "Welcome to the PhoneBook App!\n";
	std::cout << "Please add some contacts!\n";
	while (true)
	{
		if (PrintMenu(data))
			break;
	}
}
 /**
  * @brief This recursive behemoth is what searches for the Contact array for an valid
  * contact that we want to search and prints its details, if you don't try to break it,
  * otherwise it either uses
  * @param data
  * @return
  */
int SearchContact(PhoneBook &data)
{
	int index;
	Contact *temp = data.GetContacts();
	std::string firstName, lastName, nickName;

	// Check if table is empty or not;
//	std::cout << data.GetCurrentIndex() << std::endl;
	if (temp[0].GetFirstName().empty())
	{
		system("clear");
		std::cout << "The table is empty!" << std::endl;
		return 0;
	}
	else
	{
		std::cout << std::setw(10) << std::right << "Index" <<  " | ";
		std::cout << std::setw(10) << std::left << "FirstName" <<  " | ";
		std::cout << std::setw(10) << std::left << "LastName" <<  " | ";
		std::cout << std::setw(10) << std::left << "Nickname" <<  std::endl;
	}

	// Print the existing contacts
	for(int i = 0; i < PhoneBook::GetMax(); i++)
	{
		if (temp[i].GetFirstName().empty())
			break ;
		firstName = removeWhitespace(temp[i].GetFirstName());
		lastName = removeWhitespace(temp[i].GetLastName());
		nickName = removeWhitespace(temp[i].GetNickname());

		if (firstName.size() > 10) firstName = firstName.substr(0, 9) + ".";
		if (nickName.size() > 10) nickName = nickName.substr(0, 9) + ".";
		if (lastName.size() > 10) lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << std::right << i << " | ";
		std::cout << std::setw(10) << std::right << firstName  << " | ";
		std::cout << std::setw(10) << std::right << lastName  << " | ";
		std::cout << std::setw(10) << std::right << nickName << std::endl;
	}

	// Grab an valid index from the user
	while (true)
	{
		index = GetIndex();
		if (index >= 0)
			break ;
		else if (index == -1) {
			std::cout << std::endl << "Stop trying to break me, goodbye!" << std::endl;
			return 1;
		}
	}

	// Check if index is valid if not return the result of a new SearchContact call

//	std::cout << "the index is: " << index << std::endl;
//	std::cout << "the current index is: " << data.GetCurrentIndex() << std::endl;
	 if (index > data.GetCurrentIndex() || temp[index].GetDarkestSecret().empty()) {
		std::cout << "This index isn't valid!" << std::endl;
		return SearchContact(data);
	} else if (index >= PhoneBook::GetMax()) {
		system("clear");
		std::cout << "This index is out of bounds, max index is "
				  << (PhoneBook::GetMax() - 1) << std::endl;
		return SearchContact(data);
	}

	 // if nothing goes wrong print the contact details
	system("clear");
	std::cout << "First Name: " << temp[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << temp[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << temp[index].GetNickname() << std::endl;
	std::cout << "Phone Number: " << temp[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << temp[index].GetDarkestSecret() << std::endl;
	std::cout << std::endl << "== LINE BREAK ==" << std::endl << std::endl;
 	return 0;
}
/**
 * @brief Updates an empty contact from the Contact array inside the Phonebook object
 * @param empty Reference to the empty contact that we want to update
 * @param input the field of the Contact object that we want to set
 * @param position the position of the contact that is currently being updated
 * @return returns false if the phone number given to the contact object is valid
 * otherwise returns true if the contact was added.
 */
bool	UpdateEmptyContact(Contact &empty, const std::string &input, int position)
{
	switch (position) {
		case 0:
			empty.SetFirstName(input);
			break ;
		case 1:
			empty.SetLastName(input);
			break ;
		case 2:
			empty.SetNickname(input);
			break;
		case 3:
			if (!isValidNumber(input)) {
				std::cout << "Invalid phone number! Clearing data and going back to main menu!" << std::endl;
				return false;
			}
			empty.SetPhoneNumber(input);
			break ;
		case 4:
			empty.SetDarkestSecret(input);
			break ;
		default:
			return false;
	}
	return true;
}
/**
 * @brief Adds a new Contact object to the PhoneBook object
 * @param data a reference to the
 * @return returns 0 if the input is invalid and the program cannot stop running
 * returns 1 if theres an fatal error that needs to close the program, like CTRL + D
 */
int AddNewContact(PhoneBook &data)
{
	Contact temp = data.GetFirstEmptyContact();
	std::string input;
	int i = 0;

	while (i < 5)
	{
		PrintPrompt(i);
		if (std::getline(std::cin, input))
		{
			if (input.empty()) {
				system("clear");
				std::cout << "No empty inputs allowed! Going back to main menu!\n";
				return 0;
			}
			else if (IsWhitespace(input))
			{
				system("clear");
				std::cout << "You gave an whitespace only string fuck off\n";
				if (temp.GetDarkestSecret().empty())
					return 0;
				return temp.ClearFields();
			}
			else if (!UpdateEmptyContact(temp, input, i))
				return temp.ClearFields();
			i++;
		}
		else if (std::cin.eof())
			return 1;
	}
	system("clear");
	std::cout << temp.GetFirstName() << " was added to the phonebook!\n";
	data.AddContact(temp);
	return 0;
}
