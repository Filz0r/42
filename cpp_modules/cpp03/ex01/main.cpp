#include <ScavTrap.hpp>

int main()
{
	ScavTrap filipe("Filipe");
	for (unsigned int k = 0; k < 52; k++)
		filipe.attack("test");
	for (int k = 0; k < 11; k++)
		filipe.takeDamage(10);

	ScavTrap filipeClone = filipe;
	filipeClone.attack("failed");

	ScavTrap test ("testing");
	for (int k = 0; k < 11; k++)
		test.takeDamage(10);
	for(int k = 0; k < 60; k++)
		test.beRepaired(k);

	test.guardGate();
	test.guardGate();
	test.guardGate();
}