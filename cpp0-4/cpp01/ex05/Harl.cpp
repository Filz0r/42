#include <Harl.hpp>

void Harl::error() { std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }

void Harl::debug() { std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl; }

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been";
	std::cout << " coming for years whereas you started working here since last month." << std::endl;
}

void Harl::complain(std::string level) {
	e_level _level = _getLevel(level);

	switch (_level) {
		case DEBUG:
			Harl::debug();
			break;
		case INFO:
			Harl::info();
			break;
		case WARNING:
			Harl::warning();
			break;
		case ERROR:
			Harl::error();
			break;
		case INVALID:
			std::cerr << "Error, invalid complain level!" << std::endl;
			break;
	}
}


e_level Harl::_getLevel(const std::string &level) {
	static std::string levels[4] = {"debug", "info", "warning", "error" };
	size_t	temp = 99;
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			temp = i;
	}
	if (temp == 99)
		return (INVALID);
	return ((e_level)temp);
}