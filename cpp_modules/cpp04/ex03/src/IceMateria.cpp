#include <IceMateria.hpp>

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &obj): AMateria("ice") {
	*this = obj;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &obj)
{

	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<  std::endl;
}

AMateria *Ice::clone() const{
	return new Ice();
}