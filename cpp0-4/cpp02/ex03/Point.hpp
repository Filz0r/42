#pragma once

#include <Fixed.hpp>

class Point
{
   public:
      Point();
      Point(float x, float y);
      Point(const Point &obj);
      ~Point();
      Point& operator = (const Point &obj);
	  bool	operator==(const Point &obj) const;
	  Fixed	getX() const;
	  Fixed	getY() const;

	  void	printValues() const;

      private:
		const Fixed x;
		const Fixed y;

};


bool	bsp(Point const a, Point const b, Point const c, Point const point);