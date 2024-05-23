#include "Serialize.hpp"

Serialize::Serialize() {
	std::cout << "Serialize Constructor called" << std::endl;
}

Serialize::~Serialize() {
	std::cout << "Serialize Destructor called" << std::endl;
}

Serialize::Serialize(const Serialize &obj) {
	(void)obj;
	std::cout << "Serialize copy constructor called" << std::endl;
}

Serialize& Serialize::operator=(const Serialize &obj)
{
	(void)obj;
	std::cout << "Serialize copy assignment operator called" << std::endl;
	return *this;
}

uintptr_t	Serialize::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serialize::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

