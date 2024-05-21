#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 145, 137) {
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default Presidential Form", 145, 137) {
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
		: AForm(obj.getName(), 145, 137) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

std::string ShrubberyCreationForm::getAsciiTree() {
	return "               ,@@@@@@@,\n"
		   "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		   "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		   "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		   "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		   "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		   "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		   "       |o|        | |         | |\n"
		   "       |.|        | |         | |\n"
		   "\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
}

void ShrubberyCreationForm::callback() const {
	std::ofstream outputFile((this->getName() + "_shrubbery").c_str());

	outputFile << ShrubberyCreationForm::getAsciiTree();
	outputFile.close(); // fun fact this isn't needed because the file gets closed by the destructor ;)
}