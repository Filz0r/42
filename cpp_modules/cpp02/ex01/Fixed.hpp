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
      	Fixed& operator = (const Fixed &obj);

		float		toFloat(void) const;
		int			toInt(void) const;
		int 		getRawBits(void) const;
		void 		setRawBits(int const raw);

   private:
		static const int	rawBits = 8;
		int 				number;


};

std::ostream& operator <<(std::ostream &os, const Fixed &obj);

#endif //FIXED_HPP