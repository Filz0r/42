#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(1) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade) {
	std::cout << "Bureaucrat Constructor called" << std::endl;

	if (_grade > 150)
		throw Bureaucrat::GradeTooLow();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHigh();
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.getName()), grade(obj.getGrade()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->grade = obj.getGrade();
		this->name = obj.getName();
	}
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

void Bureaucrat::signForm(AForm &paper) const{
	try {
		paper.beSigned(*this);
		std::cout << this->getName() << " signed " << paper.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << this->getName() << " couldn't sign " << paper.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &paper) const{
	try {
		paper.execute(*this);
		std::cout << this->getName() << " executed " << paper.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << this->getName() << " couldn't execute " << paper.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}
