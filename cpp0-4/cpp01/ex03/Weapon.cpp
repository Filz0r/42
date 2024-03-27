#include <Weapon.hpp>

Weapon::Weapon() {}

Weapon::Weapon(std::string type) { this->type = type; }

void Weapon::setType(const std::string &type) { this->type = type; }

const std::string& Weapon::getType() { return this->type; }