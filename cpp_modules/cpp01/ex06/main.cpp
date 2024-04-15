#include <Harl.hpp>

int main(int ac, char **av)
{
	(void)ac;
	Harl annoying;
	if (ac > 1)
	{
		std::string temp(av[1]);
		annoying.complain(temp);
	}
	else
		annoying.complain("test");
}