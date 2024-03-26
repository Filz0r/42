#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac > 1)
	{

		for(int i = 1; av[i]; i++)
		{
			std::string test (av[i]);
			for (int k = 0; test.c_str()[k]; k++)
				std::cout << (char)std::toupper((int)test.c_str()[k]);
			std::cout << ' ';
		}
		std::cout << "\n";
		return (0);
	}
	else
	{
		std::cerr << "You need to provide arguements bro" << std::endl;
		return (1);
	}
}
