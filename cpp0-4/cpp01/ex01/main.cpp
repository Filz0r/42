#include <Zombie.hpp>
#include <Zombie.h>

int main(void)
{
	Zombie *ptr = zombieHorde(10, "filipe");

	for(int k = 0; k < 10; k++)
		ptr[k].announce();

	delete[] ptr;
}