#include "Intern.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern() {
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern &obj) {
	(void)obj;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

const char *Intern::InvalidForm::what() const throw () {
	return "not a valid form type!";
}

form_type Intern::convertStrToForm(const std::string &form) {
	std::string formTypes[3][2] = {
			{"robotomy request", "Robotomy Request"},
			{"Presidential Pardon", "presidential pardon"},
			{"Shrubbery Creation", "shrubbery creation"}
	};
	for (size_t i = 0; i < 3; i++)
		if (formTypes[i][0] == form || formTypes[i][1] == form)
			return static_cast<form_type>(i);
	return INVALID;
}

AForm *Intern::createPresidentialForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

const Intern::FormFunction Intern::functions = {
		Intern::createRobotomyForm,
		&Intern::createPresidentialForm,
		&Intern::createShrubberyForm,
};

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	form_type type = Intern::convertStrToForm(form);
	switch (type) {

		case SHRUB:
			std::cout << "Intern creates " << target << std::endl;
			return Intern::functions[(int)SHRUB](target);
		case ROBOTOMY:
			std::cout << "Intern creates " << target << std::endl;
			return (Intern::functions[(int)ROBOTOMY])(target);
		case PARDON:
			std::cout << "Intern creates " << target << std::endl;
			return Intern::functions[(int)PARDON](target);
		default:
		case INVALID:
			throw Intern::InvalidForm();
	}
}

