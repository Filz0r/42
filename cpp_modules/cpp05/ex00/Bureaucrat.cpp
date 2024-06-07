#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(1) {
//	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name), grade(_grade) {
//	std::cout << "Bureaucrat Constructor called" << std::endl;

	if (_grade > 150)
		throw Bureaucrat::GradeTooLow();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHigh();
}

Bureaucrat::~Bureaucrat() {
//	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName()), grade(obj.getGrade()) {
//	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) {
	(void)obj;
	return *this;
}

const char *Bureaucrat::GradeTooHigh::what() const throw () {
	return "Your grade is too high bitch!";
}

const char *Bureaucrat::GradeTooLow::what() const throw () {
	return "Your grade is too low bitch!";
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}

void	Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHigh();
	this->grade--;
}


void	Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLow();
	this->grade++;
}

std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
