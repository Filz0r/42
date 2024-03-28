#include <Fixed.hpp>
int main() {

	Fixed a;
	Fixed d;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(1);

	std::cout << "A:" << a << std::endl;
	std::cout << "B:" << b << std::endl;
	std::cout << "C:" << c << std::endl;
	std::cout << "D:" << d << std::endl << std::endl;
	std::cout << "increments" << std::endl;
	std::cout << "A:" << a << std::endl;
	std::cout << "A:" << ++a << std::endl;
	std::cout << "A:" << a << std::endl;
	std::cout << "A:" << a++ << std::endl;
	std::cout << "A:" << a << std::endl << std::endl;
	std::cout << "operations" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a + c << std::endl;
	std::cout << c + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a - c << std::endl;
	std::cout << c - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a * c << std::endl;
	std::cout << c * b << std::endl << std::endl;
	std::cout << "validations" << std::endl;
	std::cout << ((a < c) ? "true" : "false") << std::endl;
	std::cout << ((a > c) ? "true" : "false") << std::endl;
	std::cout << ((a <= c) ? "true" : "false") << std::endl;
	std::cout << ((a >= c) ? "true" : "false") << std::endl;
	std::cout << ((a == c) ? "true" : "false") << std::endl;
	std::cout << ((a != c) ? "true" : "false") << std::endl;

	std::cout << "max/min" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, d) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, d) << std::endl;

	return 0;
}
//Default constructor called
//Copy constructor called
//Copy assignment operator called // <-- This line may be missing depending on your implementation
//getRawBits member function called
//Default constructor called
//Copy assignment operator called
//getRawBits member function called
//getRawBits member function called
//0
//getRawBits member function called
//0
//getRawBits member function called
//0
//Destructor called
//Destructor called
//Destructor called