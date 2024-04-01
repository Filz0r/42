#include <App.h>

bool	IsWhitespace(const std::string &str)
{
	for (int i = 0; str.c_str()[i]; i++)
		if (!std::isspace(str.c_str()[i]))
			return false;
	return true;
}

int PrintMenu(PhoneBook &data)
{
	std::string input;

	std::cout << "Please choose one of the 3 options\n";
	std::cout << "ADD" << "\t|";
	std::cout << std::setw(10) << std::right << "SEARCH" << "\t|";
	std::cout << std::setw(10) << std::right << "EXIT" << std::endl;
	while (true)
	{
		std::cout << "input: ";
		if (std::getline(std::cin, input))
		{
			if (input.empty())
			{
				std::cout << "\nNo empty inputs allowed!\n\n";
				continue;
			}
			else if (input == "EXIT") { return 1; }
			else if (input == "ADD") {
				system("clear");
				return AddNewContact(data);
			}
			else if (input == "SEARCH") {
				system("clear");
				return SearchContact(data);
			}
		}
		else if (std::cin.eof())
			return 1;
	}
}

void PrintPrompt(int position)
{
	switch (position) {
		case 0:
			std::cout << "Input first name: ";
			break ;
		case 1:
			std::cout << "Input last name: ";
			break ;
		case 2:
			std::cout << "Input nickname: ";
			break;
		case 3:
			std::cout << "Input phone number: ";
			break ;
		case 4:
			std::cout << "Input darkest secret: ";
			break ;
		default:
			break ;
	}
}

int GetIndex()
{
	int index;
	std::string input;

	std::cout << "Enter the index of the contact to display: ";
	if (std::getline(std::cin, input)) {
		if (input.empty()) {
			std::cout << "No empty inputs allowed!\n";
			return -1;
		}
		if (IsWhitespace(input)) {
			std::cout << "You gave an whitespace only string fuck off\n";
		}
		std::istringstream iss(input);
		iss >> index;
		if (iss.eof()) {
			if (index < 0) { std::cout << "Invalid input!" << std::endl; return -1;}
			return index;
		}
		else
		{
			std::cout << "Invalid input!" << std::endl;
			return -1;
		}
	}
	else if (std::cin.eof())
		return -1;
	return -1;
}

int isValidNumber(const std::string &str)
{
	int i = 0;
	if (str.c_str()[i] == '+')
		i++;
	while (str.c_str()[i])
	{
		if(!std::isdigit(str.c_str()[i]))
			return 0;
		i++;
	}
	return 1;
}

std::string removeTabs(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");;
	return (str.substr(first, (last - first + 1)));
}