#include <Bureaucrat.hpp>

int main()
{
	// Test 1 everything is fine
	{
		try
		{
			Bureaucrat filipe("filipe", 1);

			std::cout << filipe << std::endl;
			filipe.decrementGrade();
			std::cout << filipe << std::endl;
			filipe.incrementGrade();
			std::cout << filipe << std::endl;
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	// Test 2 Grades are too low
	{
		try	{
			Bureaucrat filipe("filipe", 150);

			std::cout << filipe << std::endl;
			filipe.decrementGrade();
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat filipe("filipe", 151);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// Test 3 Grades are too high
	{
		try	{
			Bureaucrat filipe("filipe", 1);

			std::cout << filipe << std::endl;
			filipe.decrementGrade();
			std::cout << filipe << std::endl;
			filipe.incrementGrade();
			std::cout << filipe << std::endl;
			filipe.incrementGrade();

		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat filipe("filipe", 0);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

}