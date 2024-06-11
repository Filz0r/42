#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::hasFailed = false;

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45) {
//	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Presidential Form", 72, 45) {
//	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
//	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
		: AForm(obj.getName(), 72, 45) {
//	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

void RobotomyRequestForm::updateFailed() {
	RobotomyRequestForm::hasFailed = !RobotomyRequestForm::hasFailed;
}

void RobotomyRequestForm::callback() const {
	if (!RobotomyRequestForm::hasFailed) {
		std::cout << this->getName() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "The robotomy on " << this->getName() << " failed." << std::endl;
	}
	RobotomyRequestForm::updateFailed();
}