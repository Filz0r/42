#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &_name, int _gradeToSign, int _gradeToExecute)
: isSigned(false), gradeToSign(AForm::checkGrade(_gradeToSign)), gradeToExecute(AForm::checkGrade(_gradeToExecute)), name(_name) {
	std::cout << "Form complex Constructor called" << std::endl;
}

AForm::AForm()
:  isSigned(false), gradeToSign(1), gradeToExecute(1), name("Undefined") {
	std::cout << "Form Constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form Destructor called" << std::endl;
}

AForm::AForm(const AForm &obj)
 : isSigned(obj.isSigned), gradeToSign(obj.gradeToSign),
 		gradeToExecute(obj.gradeToExecute), name(obj.name) {
	std::cout << "Form copy constructor called" << std::endl;
}

int AForm::checkGrade(int grade) {
	if (grade > 150)
		throw AForm::GradeTooLow();
	else if (grade < 1)
		throw AForm::GradeTooHigh();
	else
		return grade;
}

const char *AForm::GradeTooHigh::what() const throw() {
	return "the grade is too high!";
}

const char *AForm::GradeTooLow::what() const throw() {
	return "the grade is too low!";
}

const char *AForm::IsSigned::what() const throw() {
	return "is already signed!";
}

const char *AForm::IsNotSigned::what() const throw() {
	return "is not signed yet!";
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

const std::string &AForm::getName() const {
	return this->name;
}

bool AForm::isFormSigned() const {
	return this->isSigned;
}

void	AForm::beSigned(const Bureaucrat &nerd) {
	if (nerd.getGrade() > this->getGradeToSign()) {
		throw AForm::GradeTooLow();
	} else {
		if (!this->isFormSigned())
			this->isSigned = !this->isSigned;
		else
			throw AForm::IsSigned();
	}
}

std::ostream &operator <<(std::ostream &os, const AForm &obj) {
	std::string temp = obj.isFormSigned() ? "true" : "false";

	os << "Form name: " << obj.getName() << std::endl;
	os << "Is signed: " << temp << std::endl;
	os << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	os << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	return os;
}

void	AForm::execute(const Bureaucrat &exec) const {
	if (exec.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLow();
	else if (!this->isFormSigned())
		throw AForm::IsNotSigned();
	else
		this->callback();
}