#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
   public:
	  AForm(const std::string &_name, int gradeToSign, int gradeToExecute);
      AForm(const AForm &obj);
      virtual ~AForm();

	  int				getGradeToSign() const;
	  int				getGradeToExecute() const;
	  bool				isFormSigned() const;
	  void				beSigned(const Bureaucrat &nerd);
	  const std::string	&getName() const;
	  void				execute(const Bureaucrat &exec) const;

   protected:
	  virtual void callback() const = 0;


   private:
	 AForm();
	 AForm& operator=(const AForm &obj);

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

	class IsSigned: public std::exception {
	public:
		const char *what() const throw();
	};

	class IsNotSigned: public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &os, const AForm &obj);
