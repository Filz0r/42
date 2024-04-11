#include <Point.hpp>

std::string showBool(bool value)
{
	if (value)
		return "true";
	return "false";
}

int main() {

	Point test(5, 0);
	Point p1 (0, 5);
	Point p2 (5, 5);
	Point point(1, 5);

	std::cout << showBool(bsp(test, p1, p2, point)) << std::endl;
//	std::cout << showBool(p1 == p2) << std::endl;
//	std::cout << showBool(p1 == p1) << std::endl;
	return 0;
}