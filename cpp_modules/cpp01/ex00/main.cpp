#include <Zombie.hpp>
#include <Zombie.h>

int main(void)
{
	Zombie test ("filipe");
	Zombie *test1 = newZombie("ze");
	test.announce();
	test1->announce();
	randomChump("maria");
	delete test1;
}