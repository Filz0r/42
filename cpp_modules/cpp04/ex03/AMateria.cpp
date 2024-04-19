#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &obj) {
	this->type = obj.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "AMateria copy assignment operator called" << std::endl;

	return *this;
}

AMateria::AMateria(const std::string &type) {
	this->type = type;
}

const std::string &AMateria::getType() const {
	return this->type;
}

void	AMateria::use(ICharacter &target) {
	std::cout << "* A unexisting materia is used on " << target.getName() << " *" << std::endl;
}