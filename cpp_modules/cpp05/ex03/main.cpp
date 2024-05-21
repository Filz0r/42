#include <Bureaucrat.hpp>

#include <limits>
#include <cstdlib>
#include <Intern.hpp>

void	pause() {
	std::cout << "Program paused, press enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	system("clear");
	AForm *temp;
	Intern slave;
	Bureaucrat boss("ze", 1);

	{
		std::cout << std::endl << "Robotomy creation tests" << std::endl;
		try {
			temp = slave.makeForm("robotomy request", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
			temp = slave.makeForm("robotomy requesta", "otario");
			temp = slave.makeForm("Robotomy Request", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
		} catch (std::exception &e)
		{
			std::cerr << "ERROR: this happened: " << e.what() << std::endl;
		}
		pause();
		system("clear");
	}

	{
		std::cout << std::endl << "Presidential Pardon tests" << std::endl;
		try {
			temp = slave.makeForm("presidential pardon", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
			temp = slave.makeForm("presidential asda", "otario");
			temp = slave.makeForm("Presidential Pardon", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
		} catch (std::exception &e)
		{
			std::cerr << "ERROR: this happened: " << e.what() << std::endl;
		}
		pause();
		system("clear");
	}

	{
		std::cout << std::endl << "Shrubbery Creation tests" << std::endl;
		try {
			temp = slave.makeForm("Shrubbery Creation", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
			temp = slave.makeForm("Shrubbery Creationasdsa", "otario");
			temp = slave.makeForm("shrubbery creation", "otario");
			boss.signForm(*temp);
			boss.executeForm(*temp);
			delete temp;
		} catch (std::exception &e)
		{
			std::cerr << "ERROR: this happened: " << e.what() << std::endl;
		}
		pause();
		system("clear");
	}
}