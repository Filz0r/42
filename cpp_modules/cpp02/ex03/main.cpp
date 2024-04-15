#include <Point.hpp>

static std::string showBool(bool value)
{
	if (value)
		return "true";
	return "false";
}

int main() {

	Point test(5, 0);
	Point p1 (0, 5);
	Point p2 (5, 5);

	std::cout << showBool(bsp(test, p1, p2, Point(4, 3))) << std::endl;
	std::cout << showBool(bsp(test, p1, p2, Point(-1, -1))) << std::endl;
	std::cout << showBool(bsp(test, p1, p2, Point(1, 5))) << std::endl;

	return 0;
}