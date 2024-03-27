#include <HumanA.hpp>
#include <HumanB.hpp>

int main(void)
{
	Weapon shino ("knife");
	Weapon katana ("Katana");
	HumanA a("Filipe", shino);
	HumanB b("B_Filipe");
	a.attack();
	b.attack();
	b.giveWeapon(katana);
	b.attack();
	b.giveWeapon("Bazooka");
	b.attack();
	shino.setType("shino");
	a.attack();
}