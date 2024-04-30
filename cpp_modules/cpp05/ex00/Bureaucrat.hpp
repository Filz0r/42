#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
   public:
	  Bureaucrat(std::string _name, int _grade);
      Bureaucrat(const Bureaucrat &obj);
      Bureaucrat& operator = (const Bureaucrat &obj);
	  ~Bureaucrat();

	  const std::string &getName() const;
	  int	getGrade() const;

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
		std::string 	name;
		int					grade;

		Bureaucrat();
};

std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj);