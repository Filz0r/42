#include <App.h>

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

int SearchContact(PhoneBook &data)
{
	Contact *temp = data.GetContacts();
	int index;
	std::string firstName, lastName, nickName;

	if (data.GetCurrentIndex() == -1 && temp[0].GetFirstName().empty())
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
	for(int i = 0; i < data.GetMax(); i++)
	{
		if (temp[i].GetFirstName().empty())
			break ;
		firstName = removeTabs(temp[i].GetFirstName());
		lastName = removeTabs(temp[i].GetLastName());
		nickName = removeTabs(temp[i].GetNickname());

		if (firstName.size() > 10) firstName = firstName.substr(0, 9) + ".";
		if (nickName.size() > 10) nickName = nickName.substr(0, 9) + ".";
		if (lastName.size() > 10) lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << std::right << i << " | ";
		std::cout << std::setw(10) << std::right << firstName  << " | ";
		std::cout << std::setw(10) << std::right << lastName  << " | ";
		std::cout << std::setw(10) << std::right << nickName << std::endl;
	}

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
	std::cout << "the index is: " << index << std::endl;
	std::cout << "the current index is: " << data.GetCurrentIndex() << std::endl;
	 if (index > data.GetCurrentIndex() && index < data.GetMax() && temp[index].GetDarkestSecret().empty()){
		std::cout << "This entry hasn't been added to the PhoneBook yet!" << std::endl;

		if (SearchContact(data))
			return 1;
		else
			return 0;

	} else if (index >= data.GetMax()) {
		system("clear");
		std::cout << "This index is out of bounds, max index is "
				  << (data.GetMax() - 1) << std::endl;
		if (SearchContact(data))
			return 1;
		else
			return 0;
	}
	system("clear");
	std::cout << "First Name: " << temp[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << temp[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << temp[index].GetNickname() << std::endl;
	std::cout << "Phone Number: " << temp[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << temp[index].GetDarkestSecret() << std::endl;
	std::cout << std::endl << "== LINE BREAK ==" << std::endl << std::endl;
 	return 0;
}

bool	UpdateEmptyContact(Contact &empty, const std::string &input ,int position)
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
