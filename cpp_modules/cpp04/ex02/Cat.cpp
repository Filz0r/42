#include "Cat.hpp"

Cat::Cat() {
	this->Animal::type = "Cat";
	this->type = this->Animal::type;
	this->grayMatter = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->grayMatter;
}

Cat::Cat(const Cat &obj): Animal(obj.type) {
//	*this = obj;
	this->grayMatter = new Brain(*obj.grayMatter);
	this->type = obj.Cat::type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type = obj.Cat::type;
		delete this->grayMatter;
		this->grayMatter = new Brain(*obj.grayMatter);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

std::string *Cat::getIdeas() const{
	return this->grayMatter->getIdeas();
}