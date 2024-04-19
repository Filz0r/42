#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const std::string &_type) {
	this->type = _type;
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &obj) {
	*this = obj;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
	}
	return *this;
}


std::string Animal::getType() {
	return type;
}

std::string *Animal::getIdeas() const{
	return NULL;
}