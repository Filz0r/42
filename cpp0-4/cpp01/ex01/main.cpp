#include <Zombie.hpp>
#include <Zombie.h>

int main(void)
{
	Zombie *ptr = zombieHorde(10, "filipe");

	if (!ptr)
		return 1;
	for(int k = 0; k < 10; k++)
		ptr[k].announce();

	delete[] ptr;
	return 0;
}