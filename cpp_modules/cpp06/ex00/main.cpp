#include <ScalarConverter.hpp>
#include <Tester.hpp>

int main(int ac, char **av)
{
	if (ac > 2) {
		std::cerr << "Invalid number of arguments\nUsage: ./convert <value_to_convert>" << std::endl;
		return 1;
	} else if (ac == 2) {
		std::string toConvert(av[1]);
		ScalarConverter::convert(toConvert);
	} else
		Tester::run();
	return 0;
}