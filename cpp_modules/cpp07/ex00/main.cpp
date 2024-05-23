#include <whatever.hpp>
#include <iostream>

int main() {

	// Swap tests
	{
		int t1, t2;
		std::string t3 = "hello", t4 = "world";
		t1 = 1;
		t2 = 2;
		std::cout << t1 << std::endl;
		std::cout << t2 << std::endl;
		::swap<int>(t1, t2);
		std::cout << t1 << std::endl;
		std::cout << t2 << std::endl;

		std::cout << t3 << std::endl;
		std::cout << t4 << std::endl;
		::swap<std::string>(t3, t4);
		std::cout << t3 << std::endl;
		std::cout << t4 << std::endl;
	}
	//min tests
	{
		int t1 = 1, t2 = 2;
		std::string t3 = "a", t4 = "b";

		std::cout << ::min<int>(t1, t2) << std::endl;
		std::cout << ::min<std::string>(t3, t4) << std::endl;
	}

	//max tests
	{
		int t1 = 1, t2 = 2;
		std::string t3 = "a", t4 = "b";

		std::cout << ::max<int>(t1, t2) << std::endl;
		std::cout << ::max<std::string>(t3, t4) << std::endl;
	}
}