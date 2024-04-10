#include <HumanA.hpp>
#include <HumanB.hpp>

int main(void)
{
	Weapon shino ("knife");
	HumanA a("Filipe", shino);
	HumanB b("B_Filipe");
	a.attack();
	b.attack();
	b.giveWeapon(shino);
	b.attack();
	shino.setType("shino");
	a.attack();
}