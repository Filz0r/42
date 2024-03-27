#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie(const std::string &name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "The zombie named: " << this->name << " was destroyed!" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}