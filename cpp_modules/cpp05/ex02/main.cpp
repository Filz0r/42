#include <Bureaucrat.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <limits>
#include <cstdlib>

void	pause() {
	std::cout << "Program paused, press enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	system("clear");
	{
		std::cout << "Presidential Pardon Tests" << std::endl << std::endl;

		Bureaucrat chump("Chump", 150);
		Bureaucrat boss("Idiot Boss", 6);
		Bureaucrat boss2("Not so Idiot Boss", 5);

		PresidentialPardonForm form("presidential_idiot");

		std::cout << std::endl;

		boss.executeForm(form);
		boss.signForm(form);
		boss2.executeForm(form);
		boss.executeForm(form);
		std::cout << std::endl;
		std::cout << "------------------" << std::endl;
	}

	pause();
	system("clear");

	{
		std::cout << "Robotomy request Tests" << std::endl << std::endl;

		Bureaucrat boss("Idiot Boss", 82);
		Bureaucrat boss2("Not so Idiot Boss", 45);

		RobotomyRequestForm form("robotomy_form");
		RobotomyRequestForm form2("stupid_robotomy_form");

		std::cout << std::endl;

		boss.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss.signForm(form);
		std::cout << "------------------" << std::endl;
		boss2.signForm(form);
		std::cout << "------------------" << std::endl;
		boss.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form);
		std::cout << "------------------" << std::endl;

		boss2.signForm(form2);
		std::cout << "------------------" << std::endl;
		boss2.executeForm(form2);
		std::cout << "------------------" << std::endl;

		std::cout << std::endl;
		std::cout << "------------------" << std::endl;
	}

	pause();
	system("clear");

	{
		std::cout << "Shrubbery Creation Tests" << std::endl << std::endl;

		Bureaucrat boss("Idiot Boss", 82);
		Bureaucrat boss2("Not so Idiot Boss", 45);

		ShrubberyCreationForm form("shrub_form");

		std::cout << std::endl;

		boss.signForm(form);
		std::cout << "------------------" << std::endl;
		boss.executeForm(form);
		std::cout << "------------------" << std::endl;
		std::cout << std::endl;
	}

	pause();
}