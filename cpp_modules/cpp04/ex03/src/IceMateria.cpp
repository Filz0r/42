#include <IceMateria.hpp>

Ice::Ice() : AMateria("ice") {
	this->AMateria::value = 50;
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &obj): AMateria("ice") {
	this->AMateria::value = obj.getValue();
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &obj) {
	std::cout << "Ice copy assignment operator called" << std::endl;

	if (this != &obj)
		this->AMateria::value = obj.getValue();
//		this->type = obj.type;
	return *this;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<  std::endl;
//	this->doDamage(target);
}

AMateria *Ice::clone() const {
	return new Ice();
}

size_t	Ice::getValue() const {
	return this->AMateria::value;
}

//void	Ice::doDamage(ICharacter &target) const {
//	if (target.getHitpoints() > 0)
//	{
//		target.changeHitpoints(this->getValue(), true);
//	   std::cout << "* and deals " << this->getValue() << " points of damage! *" << std::endl;
//	}
//	else
//		std::cout << "* but " << target.getName() << " is already dead! *" <<  std::endl;
//}
//
//void	Ice::restoreHitpoints(ICharacter &target) const {
//	(void)target;
//	std::cout << "if this method is called it means that the Materia is not a Cure Materia" << std::endl;
//}