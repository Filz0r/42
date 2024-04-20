#include <CureMateria.hpp>

Cure::Cure() : AMateria("cure"){
	this->AMateria::value = 50;
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &obj): AMateria("cure") {
//	*this = obj;
	this->AMateria::value = obj.getValue();
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &obj)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	this->AMateria::value = obj.getValue();
	//	if (this != &obj)
//		this->type = obj.type;
	return *this;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" <<  std::endl;
//	this->restoreHitpoints(target);
}

AMateria *Cure::clone() const{
	return new Cure();
}

size_t	Cure::getValue() const {
	return this->AMateria::value;
}

//void	Cure::doDamage(ICharacter &target) const {
//	(void)target;
//	std::cout << "This method should not be called for a Cure Materia" << std::endl;
//}

//void	Cure::restoreHitpoints(ICharacter &target) const {
//	if (target.getHitpoints() > 0)
//	{
//		target.changeHitpoints(this->getValue(), false);
//		std::cout << "* and restores " << this->getValue() << " hitpoints! *" << std::endl;
//	}
//	else
//		std::cout << "* but " << target.getName() << " is already dead! *" <<  std::endl;
//}