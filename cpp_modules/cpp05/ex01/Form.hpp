#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
   public:
	  Form(const std::string &_name, int gradeToSign, int gradeToExecute);
      Form(const Form &obj);
      ~Form();
      Form& operator = (const Form &obj);

	  int				getGradeToSign() const;
	  int				getGradeToExecute() const;
	  bool				isFormSigned() const;
	  void				beSigned(const Bureaucrat &nerd);
	  const std::string	&getName() const;

  private:
	 Form();

	 bool				isSigned;
	 const int 			gradeToSign;
	 const int 			gradeToExecute;
	 const std::string	name;

	 static int checkGrade(int grade);

	 class GradeTooHigh: public std::exception {
	 public:
	 	const char *what() const throw();
	 };

	 class GradeTooLow: public std::exception {
	 public:
	 	const char *what() const throw();
	 };
};

std::ostream &operator <<(std::ostream &os, const Form &obj);
