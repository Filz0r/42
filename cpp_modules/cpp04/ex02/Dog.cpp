#include "Dog.hpp"

Dog::Dog() {
	this->Animal::type = "Dog";
	this->type = this->Animal::type;
	this->grayMatter = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->grayMatter;
}

Dog::Dog(const Dog &obj): Animal(obj.type) {
	this->grayMatter = new Brain(*obj.grayMatter);
	this->type = obj.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete this->grayMatter;
		this->grayMatter = new Brain(*obj.grayMatter);
		this->type = obj.type;
	}
	return *this;
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof" << std::endl;
}

std::string *Dog::getIdeas() const{
	return this->grayMatter->getIdeas();
}