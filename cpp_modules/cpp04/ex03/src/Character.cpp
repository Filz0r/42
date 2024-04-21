#include "Character.hpp"

Character::Character() {
	std::cout << "Character Constructor called" << std::endl;

	this->name = "default";
	this->hitpoints = 500;
	for (size_t i = 0; i < Character::maxIndex; i++)
		this->materias[i] = NULL;
}

Character::Character(const std::string &_name) {
	std::cout << "Character Constructor called" << std::endl;

	this->name = _name;
	this->hitpoints = 500;
	for (size_t i = 0; i < Character::maxIndex; i++)
		this->materias[i] = NULL;
}

Character::~Character() {
	std::cout << "Character Destructor called" << std::endl;

	for (size_t i = 0; i < Character::maxIndex; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}

Character::Character(const Character &obj)  : ICharacter(obj) {
	std::cout << "Character copy constructor called" << std::endl;

//	std::cout << "address: " << this << std::endl;
//	std::cout << "object address: " << &obj << std::endl;
//	std::cout << "object name: " << obj.name << std::endl;
//	std::cout << "materias address: " << obj.materias << std::endl;

	this->name = std::string(obj.name);
	this->hitpoints = obj.hitpoints;
	for (size_t k = 0; k < Character::maxIndex; k++)
	{
		this->materias[k] = NULL;
		if (obj.materias[k] != NULL)
		{
			this->materias[k] = obj.materias[k]->clone();
//			std::cout << "materias type: " << obj.materias[k]->getType() << std::endl;
//			std::cout << "materias address: " << obj.materias[k] << std::endl;
		}
	}
}

Character& Character::operator=(const Character &obj)
{
	std::cout << "Character copy assignment operator called" << std::endl;

//	std::cout << "address: " << this << std::endl;
//	std::cout << "object address: " << &obj << std::endl;
//	std::cout << "object name: " << obj.name << std::endl;
//	std::cout << "materias address: " << obj.materias << std::endl;

	if (this != &obj) {
		this->name = std::string(obj.name);
		this->hitpoints = obj.hitpoints;
		for (size_t k = 0; k < Character::maxIndex; k++) {
			if (this->materias[k]) {
				delete this->materias[k];
				this->materias[k] = NULL;
			}
			if (obj.materias[k] != NULL) {
				this->equip(obj.materias[k]->clone());
//			std::cout << "materias type: " << obj.materias[k]->getType() << std::endl;
//			std::cout << "materias address: " << obj.materias[k] << std::endl;
			}
		}
	}
	return *this;
}

int Character::getHitpoints() const {
	return this->hitpoints;
}

void Character::changeHitpoints(size_t value, bool isDamage) {
	if (isDamage)
	{
		if (this->hitpoints < (int)value)
			this->hitpoints = 0;
		else
			this->hitpoints -= (int)value;
	}
	else
	{
		if (this->hitpoints + (int)value > Character::maxHitponts)
			this->hitpoints = Character::maxHitponts;
		else
			this->hitpoints += (int)value;
	}
}

const std::string &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;

	for (size_t i = 0; i < Character::maxIndex; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || (size_t)idx >= Character::maxIndex || !this->materias[idx])
		return ;

	this->materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || (size_t)idx >= Character::maxIndex || !this->materias[idx])
		return ;

	this->materias[idx]->use(target);
}