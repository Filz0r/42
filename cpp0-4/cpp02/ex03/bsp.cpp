#include <Point.hpp>

// Formula -> 1 half of the absolute value of the sums
// A = 	1/2 | (ax*by) + (bx*cy) + (cx*ay) - (ax*cy) - (bx*ay) - (cx*by) |

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
   // Triangle area based on a, b and c Points
	Fixed sumsABC = (a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY())
			- (a.getX() * c.getY()) - (b.getX() * a.getY()) - (c.getX() * b.getY());
	Fixed positiveABC = sumsABC.toAbsolute();
	Fixed areaABC = 0.5f * positiveABC.toFloat();

	// Triangle area based on a, b and point Points
	Fixed sumsABPoint = (a.getX() * b.getY()) + (b.getX() * point.getY()) + (point.getX() * a.getY())
					- (a.getX() * point.getY()) - (b.getX() * a.getY()) - (point.getX() * b.getY());
	Fixed positiveABPoint = sumsABPoint.toAbsolute();
	Fixed areaABPoint = 0.5f * positiveABPoint.toFloat();

	// Triangle area based on a, point and c Points
	Fixed sumsACPoint = (a.getX() * point.getY()) + (point.getX() * c.getY()) + (c.getX() * a.getY())
					- (a.getX() * c.getY()) - (point.getX() * a.getY()) - (c.getX() * point.getY());
	Fixed positiveACPoint = sumsACPoint.toAbsolute();
	Fixed areaACPoint = 0.5f * positiveACPoint.toFloat();

	// Triangle area based on point, b and c Points
	Fixed sumsBCPoint = (point.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * point.getY())
					- (point.getX() * c.getY()) - (b.getX() * point.getY()) - (c.getX() * b.getY());
	Fixed positiveBCPoint = sumsBCPoint.toAbsolute();
	Fixed areaBCPoint = 0.5f * positiveBCPoint.toFloat();


//	std::cout << "abc area: " << areaABC << std::endl;
//	std::cout << "abpoint area: " << areaABPoint << std::endl;
//	std::cout << "acpoint area: " << areaACPoint << std::endl;
//	std::cout << "bcpoint area: " << areaBCPoint << std::endl;

	// check if the point is a vertex
	if (point == a || point == b || point == c)
		return false;
	else
	{
		// Check if the sum of all of the smaller areas are equal to the triangle area
		if (areaABC == (areaABPoint + areaACPoint + areaBCPoint))
		{
			//if  any of the areas are 0 it means that the point is on a edge
			if (areaBCPoint == 0 || areaABPoint == 0 || areaACPoint == 0)
				return false;
			return true;
		}
	}
	return false;
}