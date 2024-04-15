#include "Fixed.hpp"

Fixed::Fixed() : number(0) {
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Fixed copy constructor called" << std::endl;

	this->number = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	std::cout << "Fixed copy assignment operator called" << std::endl;

	if (this != &obj)
		this->number = obj.getRawBits();

	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}
