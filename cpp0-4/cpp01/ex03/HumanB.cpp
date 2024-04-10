#include <HumanB.hpp>

HumanB::HumanB(const std::string &name) {
	this->name = name;
	this->weapon = NULL;
}

void HumanB::giveWeapon(Weapon &thing) { weapon = &thing; }

void HumanB::attack() {
	if (!this->weapon || this->weapon->getType().empty())
		std::cout << this->name << " attacks with their non-existing weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}