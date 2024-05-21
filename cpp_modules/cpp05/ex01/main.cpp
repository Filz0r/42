#include <Bureaucrat.hpp>
#include <Form.hpp>
int main()
{
	Bureaucrat chump("Chump", 150);
	Bureaucrat boss("Boss", 1);

	{
		Form test("hello", 150, 150);
		Form test1("hello 1", 15, 15);

		std::cout << std::endl << "test 1" << std::endl << std::endl;
		try
		{
			chump.signForm(test);
			chump.signForm(test1);
			chump.signForm(test);
			boss.signForm(test1);
		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----------------" << std::endl;
	}
	{
		Form test("hello world", 150, 150);
		std::cout << std::endl << "test 2" << std::endl << std::endl;
		try {
			test.beSigned(chump);
			std::cout << "The form named " << test.getName() << " was signed" << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			test.beSigned(chump);
		} catch (const std::exception &e) {
			std::cerr << "Error signing form because, the form ";
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----------------" << std::endl;
	}

	{
		Form test("hello world", 150, 150);
		std::cout << std::endl << "test 3" << std::endl << std::endl;
		std::cout << test << std::endl;
		boss.signForm(test);
		std::cout << std::endl << test << std::endl;
		std::cout << "-----------------" << std::endl;
	}
}