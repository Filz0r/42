#pragma once

#include <AForm.hpp>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm();

private:
	// helper function that returns an ascii tree to be saved on a file
	static std::string getAsciiTree();

	ShrubberyCreationForm();
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm &obj);
	void callback() const;
};