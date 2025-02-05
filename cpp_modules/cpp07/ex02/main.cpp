#include <Array.hpp>

int main() {
	{
 		Array<int> test;

		try {
			test[0] = 0;
			std::cout << "added 0 on position 0 " << std::endl;
		} catch (std::exception &e)	{
			std::cerr << "first" << std::endl;
			std::cerr << e.what() << std::endl;
		}
		try {
			test[1] = 0; // should throw
			std::cout << "added 0 on position 1 " << std::endl;
		} catch (std::exception &e)	{
			std::cerr << "second" << std::endl;
			std::cerr << e.what() << std::endl;
		}

		try {
			test[-1] = 0; // should throw
			std::cout << "added 0 on position -1 " << std::endl;
		} catch (std::exception &e)	{
			std::cerr << "second" << std::endl;
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----------------" << std::endl;

	}

	{
		Array<size_t> test(10);
		for (size_t i = 0; i < test.size(); i++)
			test[i] = i * 2;
		try {
			for (size_t i = 0; i < test.size() + 1; i++) {
				std::cout << "Index: " << i;
				std::cout << " | Value: " << test[i] << std::endl;
				std::cout << "-----------------" << std::endl;

			}
				// is going to throw on the last iteration
				// Index of 10 doesn't exist in a array of size 10

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "-----------------" << std::endl;
		std::cout << "size of array: " << test.size() << std::endl;
	}

}

//#include <iostream>
//#include <Array.hpp>
//#include <cstdlib>
//
//#define MAX_VAL 750
//int main(int, char**)
//{
//	Array<int> numbers(MAX_VAL);
//	int* mirror = new int[MAX_VAL];
//	srand(time(NULL));
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		const int value = rand();
//		numbers[i] = value;
//		mirror[i] = value;
//	}
//	//SCOPE
//	{
//		Array<int> tmp = numbers;
//		Array<int> test(tmp);
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		if (mirror[i] != numbers[i])
//		{
//			std::cerr << "didn't save the same value!!" << std::endl;
//			return 1;
//		}
//	}
//	try
//	{
//		numbers[-2] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	try
//	{
//		numbers[MAX_VAL] = 0;
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//
//	for (int i = 0; i < MAX_VAL; i++)
//	{
//		numbers[i] = rand();
//	}
//	delete [] mirror;//
//	return 0;
//}