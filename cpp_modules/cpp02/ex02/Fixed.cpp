#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : number(0) {
//	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : number(nb << rawBits) {
//	std::cout << "Fixed Integer Constructor called" << std::endl;
}

Fixed::Fixed(const float nb) {
//	std::cout << "Fixed Float Constructor called" << std::endl;
	this->number = (int)roundf(nb * (1 << rawBits));
}

Fixed::Fixed(const Fixed &obj) {
//	std::cout << "Fixed copy constructor called" << std::endl;
	this->number = obj.getRawBits();
}

Fixed::~Fixed() {
//	std::cout << "Fixed Destructor called" << std::endl;
}

bool	Fixed::operator>(const Fixed &obj) const {
	return this->getRawBits() > obj.getRawBits();
}

bool	Fixed::operator<(const Fixed &obj) const {
	return this->getRawBits() < obj.getRawBits();
}

bool	Fixed::operator>=(const Fixed &obj) const {
	return this->getRawBits() >= obj.getRawBits();
}

bool	Fixed::operator<=(const Fixed &obj) const {
	return this->getRawBits() <= obj.getRawBits();
}

bool	Fixed::operator==(const Fixed &obj) const {
	return this->getRawBits() == obj.getRawBits();
}

bool	Fixed::operator!=(const Fixed &obj) const {
	return this->getRawBits() != obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &obj) {
//	std::cout << "Fixed copy assignment operator called" << std::endl;

	if (this != &obj)
		this->number = obj.getRawBits();

	return *this;
}

Fixed Fixed::operator+(const Fixed &obj) const {
	return this->toFloat() + obj.toFloat();
}

Fixed Fixed::operator-(const Fixed &obj) const {
	return this->toFloat() - obj.toFloat();
}

Fixed Fixed::operator*(const Fixed &obj) const {
	return this->toFloat() * obj.toFloat();
}

Fixed Fixed::operator/(const Fixed &obj) const {
	return this->toFloat() / obj.toFloat();
}

Fixed Fixed::operator++(void) {
	this->number++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->number++;
	return temp;
}

Fixed Fixed::operator--(void) {
	this->number--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->number--;
	return temp;
}


int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits(const int raw) {
//	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}

int	Fixed::toInt() const {
//	std::cout << "toInt member function called" << std::endl;
	return this->number >> rawBits;
}

float Fixed::toFloat() const {
//	std::cout << "toInt member function called" << std::endl;
	return ((float)this->number / (1 << rawBits));
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

