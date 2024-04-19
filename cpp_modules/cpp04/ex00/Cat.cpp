#include "Cat.hpp"

Cat::Cat() {
	this->Animal::type = "Cat";
	this->type = this->Animal::type;
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj.type) {
	*this = obj;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.Cat::type;
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "meow" << std::endl;
}