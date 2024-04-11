#include "Point.hpp"

Point::Point() : x(0), y(0){
	std::cout << "Point Constructor called" << std::endl;
}

Point::Point(float x, float y) : x(x), y(y){
	std::cout << "Point Constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Point Destructor called" << std::endl;
}

Point::Point(const Point &obj) :
	x(obj.x), y(obj.y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &obj)
{
	std::cout << "Point copy assignment operator called" << std::endl;
	(void)obj;
	return *this;
}

void	Point::printValues() const {
	std::cout << "x is : " << this->x.toFloat() << std::endl;
	std::cout << "y is : " << this->y.toFloat() << std::endl;
}

bool	Point::operator==(const Point &obj) const {
//	std::cout << "---------------" << std::endl;
//	obj.printValues();
//	this->printValues();
//	std::cout << "---------------" << std::endl;
	return (this->x.toFloat() == obj.getX().toFloat() && this->y.toFloat() == obj.getY().toFloat());
}

Point Point::operator+(const Point &obj) const {
	return Point((this->x.toFloat() + obj.getX().toFloat()), (this->y.toFloat() + obj.getY().toFloat()));
}

Fixed	Point::getX() const { return  this->x; }
Fixed	Point::getY() const { return  this->y; }

