#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &_name, int _gradeToSign, int _gradeToExecute)
: isSigned(false), gradeToSign(Form::checkGrade(_gradeToSign)), gradeToExecute(Form::checkGrade(_gradeToExecute)), name(_name) {
//	std::cout << "Form complex Constructor called" << std::endl;
}

Form::Form()
:  isSigned(false), gradeToSign(1), gradeToExecute(1), name("Undefined") {
//	std::cout << "Form Constructor called" << std::endl;
}

Form::~Form() {
//	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &obj)
 : isSigned(obj.isSigned), gradeToSign(obj.gradeToSign),
 		gradeToExecute(obj.gradeToExecute), name(obj.name) {
//	std::cout << "Form copy constructor called" << std::endl;
}

int Form::checkGrade(int grade) {
	if (grade > 150)
		throw Form::GradeTooLow();
	else if (grade < 1)
		throw Form::GradeTooHigh();
	else
		return grade;
}

const char *Form::GradeTooHigh::what() const throw() {
	return "the grade is too high!";
}

const char *Form::GradeTooLow::what() const throw() {
	return "the grade is too low!";
}

const char *Form::IsSigned::what() const throw() {
	return "is already signed!";
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

const std::string &Form::getName() const {
	return this->name;
}

bool Form::isFormSigned() const {
	return this->isSigned;
}

void	Form::beSigned(const Bureaucrat &nerd) {
	if (nerd.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLow();
	} else {
		if (!this->isFormSigned())
			this->isSigned = !this->isSigned;
		else
			throw Form::IsSigned();
	}
}

std::ostream &operator <<(std::ostream &os, const Form &obj) {
	std::string temp = obj.isFormSigned() ? "true" : "false";

	os << "Form name: " << obj.getName() << std::endl;
	os << "Is signed: " << temp << std::endl;
	os << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	os << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	return os;
}