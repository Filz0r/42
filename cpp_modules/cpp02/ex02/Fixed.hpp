#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
   public:
      	Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
      	Fixed(const Fixed &obj);
      	~Fixed();
      	Fixed&	operator=(const Fixed &obj);
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		float		toFloat(void) const;
		int			toInt(void) const;
		int 		getRawBits(void) const;
		void 		setRawBits(int const raw);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

   private:
		static const int	rawBits = 8;
		int 				number;


};

std::ostream& operator <<(std::ostream &os, const Fixed &obj);

#endif //FIXED_HPP