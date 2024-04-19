#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->WrongAnimal::type = "WrongCat";
	this->type = this->WrongAnimal::type;
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal(obj.type) {
	*this = obj;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.WrongCat::type;
	return *this;
}

void	WrongCat::makeSound() const{
	std::cout << "meow" << std::endl;
}