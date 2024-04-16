#include <DiamondTrap.hpp>

int main() {
	DiamondTrap filipe("Filipe");
	for (unsigned int k = 0; k < 102; k++)
		filipe.attack("test");

	filipe.printStatus();
	filipe.whoAmI();
	DiamondTrap test = filipe;
	test.guardGate();
	test.highFivesGuys();2
	test.printStatus();
	test.whoAmI();
}