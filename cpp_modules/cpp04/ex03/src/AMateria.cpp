#include <Interfaces.hpp>

AMateria::AMateria() {
	this->value = 0;
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &obj) {
	std::cout << "AMateria copy constructor called" << std::endl;

	this->type = obj.type;
	this->value = obj.value;
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;

	if (this != &obj)
	{
		this->type = obj.type;
		this->value = obj.value;
	}
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