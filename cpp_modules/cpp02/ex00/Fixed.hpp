#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
   public:
      	Fixed();
      	Fixed(const Fixed &obj);
      	~Fixed();
      	Fixed& operator = (const Fixed &obj);

		int 		getRawBits(void) const;
		void 		setRawBits(int const raw);

      private:
		static const int	rawBits = 8;
		int 				number;


};
#endif //FIXED_HPP