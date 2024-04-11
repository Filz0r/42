#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("John Doe"), hitpoints(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
		: name(name), hitpoints(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : hitpoints(obj.hitpoints), energy(obj.energy), damage(0)  {
	std::cout << "ClapTrap copy constructor called" << std::endl;

	this->name = obj.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &obj)
		this->name = obj.name;

	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name <<  " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
	else
		std::cout << "ClapTrap " << this->name << " tried to attack " << target << " but he doesn't have anymore energy left!" << std::endl;
}

void	ClapTrap::beRepaired (unsigned int value) {
	if (this->energy > 0)
	{
		if (this->hitpoints + value <= 10)
		{
			this->hitpoints += (int)value;
			std::cout << "ClapTrap " << this->name <<  " repairs itself and gains " << value << " of hitpoints! He now has " << this->hitpoints << " life points" << std::endl;
			this->energy--;
		}
		else
			std::cout << "ClapTrap " << this->name << " cannot have more than 10 hitpoints. Current hitpoints: " << this->hitpoints << " tried to give him " << value << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " tried to heal himself but he doesn't have anymore energy left!" << std::endl;
}

void	ClapTrap::takeDamage (unsigned int value) {
	if (this->hitpoints > 0)
	{
		this->hitpoints -= (int)value;
		if (this->hitpoints < 0)
			this->hitpoints = 0;
		std::cout << "ClapTrap " << this->name <<  " takes " << value << " of damage! He now has " << this->hitpoints << " life points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have any hitpoints left!" << std::endl;
}