#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5) {
//	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Form", 25, 5) {
//	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
//	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: AForm(obj.getName(), 25, 5) {
//	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

void PresidentialPardonForm::callback() const {
//	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}