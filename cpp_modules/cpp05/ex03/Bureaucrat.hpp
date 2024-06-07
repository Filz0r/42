#pragma once

#include <iostream>
#include <exception>
#include <AForm.hpp>

class Bureaucrat
{
   public:
	  Bureaucrat(const std::string& _name, int _grade);
      Bureaucrat(const Bureaucrat &obj);
	  ~Bureaucrat();

	  const std::string &getName() const;
	  int	getGrade() const;

	  void	signForm(AForm& paper) const;
	  void	executeForm(AForm& paper) const;

	  void	incrementGrade();
	  void	decrementGrade();

	  class GradeTooHigh: public std::exception {
	  	public:
			const char *what() const throw();
	  };
	  class GradeTooLow: public std::exception {
	  	public:
		  const char *what() const throw();
	  };
      
   private:
		const std::string name;
		int			grade;

		Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat &obj);

};

std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj);