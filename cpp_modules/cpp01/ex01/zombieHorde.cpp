#include <Zombie.h>

Zombie *zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;

	Zombie *ptr = new Zombie[N];

	for (int i = 0; i < N; i++)
		ptr[i].setName(name);

	return ptr;
}