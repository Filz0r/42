#include <Extras.hpp>

Fire::Fire() : AMateria("fire") {
	this->AMateria::value = 100;
	std::cout << "Fire Constructor called" << std::endl;
}

Fire::~Fire() {
	std::cout << "Fire Destructor called" << std::endl;
}

Fire::Fire(const Fire &obj): AMateria("fire") {
	this->AMateria::value = obj.getValue();
	std::cout << "Fire copy constructor called" << std::endl;
}

Fire& Fire::operator=(const Fire &obj) {
	std::cout << "Fire copy assignment operator called" << std::endl;

	if (this != &obj)
		this->AMateria::value = obj.getValue();
//		this->type = obj.type;
	return *this;
}

void Fire::use(ICharacter &target) {
	std::cout << "* shoots an Fire bolt at " << target.getName() << " *" <<  std::endl;
//	this->doDamage(target);
}

AMateria *Fire::clone() const {
	return new Fire();
}

size_t	Fire::getValue() const {
	return this->AMateria::value;
}

//void	Fire::doDamage(ICharacter &target) const {
//	if (target.getHitpoints() > 0)
//	{
//		target.changeHitpoints(this->getValue(), true);
//	   std::cout << "* and deals " << this->getValue() << " points of damage! *" << std::endl;
//	}
//	else
//		std::cout << "* but " << target.getName() << " is already dead! *" <<  std::endl;
//}
//
//void	Fire::restoreHitpoints(ICharacter &target) const {
//	(void)target;
//	std::cout << "if this method is called it means that the Materia is not a Cure Materia" << std::endl;
//}

Wind::Wind() : AMateria("wind") {
	this->AMateria::value = 50;
	std::cout << "Wind Constructor called" << std::endl;
}

Wind::~Wind() {
	std::cout << "Wind Destructor called" << std::endl;
}

Wind::Wind(const Wind &obj): AMateria("wind") {
	this->AMateria::value = obj.getValue();
	std::cout << "Wind copy constructor called" << std::endl;
}

Wind& Wind::operator=(const Wind &obj) {
	std::cout << "Wind copy assignment operator called" << std::endl;

	if (this != &obj)
		this->AMateria::value = obj.getValue();
//		this->type = obj.type;
	return *this;
}

void Wind::use(ICharacter &target) {
	std::cout << "* shoots an Wind gust at " << target.getName() << " *" <<  std::endl;
//	this->doDamage(target);
}

AMateria *Wind::clone() const {
	return new Wind();
}

size_t	Wind::getValue() const {
	return this->AMateria::value;
}

//void	Wind::doDamage(ICharacter &target) const {
//	if (target.getHitpoints() > 0)
//	{
//		target.changeHitpoints(this->getValue(), true);
//	   std::cout << "* and deals " << this->getValue() << " points of damage! *" << std::endl;
//	}
//	else
//		std::cout << "* but " << target.getName() << " is already dead! *" <<  std::endl;
//}
//
//void	Wind::restoreHitpoints(ICharacter &target) const {
//	(void)target;
//	std::cout << "if this method is called it means that the Materia is not a Cure Materia" << std::endl;
//}


Death::Death() : AMateria("death") {
	this->AMateria::value = 1500;
	std::cout << "Death Constructor called" << std::endl;
}

Death::~Death() {
	std::cout << "Death Destructor called" << std::endl;
}

Death::Death(const Death &obj): AMateria("death") {
	this->AMateria::value = obj.getValue();
	std::cout << "Death copy constructor called" << std::endl;
}

Death& Death::operator=(const Death &obj) {
	std::cout << "Death copy assignment operator called" << std::endl;

	if (this != &obj)
		this->AMateria::value = obj.getValue();
//		this->type = obj.type;
	return *this;
}

void Death::use(ICharacter &target) {
	std::cout << "* just kills " << target.getName() << " *" <<  std::endl;
//	this->doDamage(target);
}

AMateria *Death::clone() const {
	return new Death();
}

size_t	Death::getValue() const {
	return this->AMateria::value;
}

//void	Death::doDamage(ICharacter &target) const {
//	if (target.getHitpoints() > 0)
//		target.changeHitpoints(this->getValue(), true);
//	else
//		std::cout << "* but " << target.getName() << " is already dead! *" <<  std::endl;
//}

//void	Death::restoreHitpoints(ICharacter &target) const {
//	(void)target;
//	std::cout << "if this method is called it means that the Materia is not a Cure Materia" << std::endl;
//}


Revive::Revive() : AMateria("revive") {
	this->AMateria::value = 1500;
	std::cout << "Revive Constructor called" << std::endl;
}

Revive::~Revive() {
	std::cout << "Revive Destructor called" << std::endl;
}

Revive::Revive(const Revive &obj): AMateria("revive") {
	this->AMateria::value = obj.getValue();
	std::cout << "Revive copy constructor called" << std::endl;
}

Revive& Revive::operator=(const Revive &obj) {
	std::cout << "Revive copy assignment operator called" << std::endl;

	if (this != &obj)
		this->AMateria::value = obj.getValue();
//		this->type = obj.type;
	return *this;
}

void Revive::use(ICharacter &target) {
	std::cout << "* revives " << target.getName() << " *" <<  std::endl;
//	this->restoreHitpoints(target);
}

AMateria *Revive::clone() const {
	return new Revive();
}

size_t	Revive::getValue() const {
	return this->AMateria::value;
}
//
//void	Revive::doDamage(ICharacter &target) const {
//	(void)target;
//	std::cout << "This method should not be called for a Revive Materia" << std::endl;
//}
//
//void	Revive::restoreHitpoints(ICharacter &target) const {
//	if (target.getHitpoints() <=  0)
//	{
//		target.changeHitpoints(this->getValue(), false);
//		std::cout << "* and restores " << target.getName() << " to full health! *" <<  std::endl;
//	}
//	else
//		std::cout << "* but " << target.getName() << " isn't dead yet! *" <<  std::endl;
//}