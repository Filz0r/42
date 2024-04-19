#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I don't think, I'm an animal";
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &obj) {
	*this = obj;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0 ; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

std::string *Brain::getIdeas() {
	return this->ideas;
}