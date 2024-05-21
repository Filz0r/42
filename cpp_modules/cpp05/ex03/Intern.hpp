#pragma once

#include <iostream>
#include <exception>

class AForm;

enum form_type{
	ROBOTOMY,
	PARDON,
	SHRUB,
	INVALID,
};

class Intern
{
   public:
      Intern();
      Intern(const Intern &obj);
      ~Intern();
      Intern& operator = (const Intern &obj);

	  AForm	*makeForm(const std::string &form, const std::string &target);

      private:
		typedef AForm *(*FormFunction[3])(const std::string &target);
		const static FormFunction functions;
		static AForm	*createPresidentialForm(const std::string &target);
		static AForm	*createRobotomyForm(const std::string &target);
		static AForm	*createShrubberyForm(const std::string &target);
		static form_type convertStrToForm(const std::string &form);

		class InvalidForm: public std::exception {
		public:
			const char *what() const throw();
		};
};

