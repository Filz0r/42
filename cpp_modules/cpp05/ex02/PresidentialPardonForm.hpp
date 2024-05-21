#pragma once

#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
   public:
      	PresidentialPardonForm();
	  	PresidentialPardonForm(const std::string &target);
      	PresidentialPardonForm(const PresidentialPardonForm &obj);
	  	~PresidentialPardonForm();

  	private:
		PresidentialPardonForm& operator = (const PresidentialPardonForm &obj);
		void callback() const;


};