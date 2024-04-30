#include <Bureaucrat.hpp>
#include <Form.hpp>
int main()
{
	{
		try
		{
			Form test("hello", 150, 150);
			Bureaucrat chump("Chump", 150);

			chump.signForm(test);
			test.beSigned(chump);

		}
		catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
}