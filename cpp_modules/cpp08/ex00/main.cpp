#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <set>

int main() {
	{
		std::cout << "Vector tests:" << std::endl;
		std::vector<int> test;

		for (int i = 0; i < 10; i++)
			test.push_back(i * 2);

		std::cout << "Elements inside the vector: ";
		for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it) {
			std::cout << *it;
			if (it + 1 == test.end())
				std::cout << std::endl;
			else
				std::cout << " ";
		}

		try {
			std::cout << "looking for number 2 in the vector" << std::endl;
			std::vector<int>::const_iterator val = ::easyfind(test, 2);
			std::cout << "value: " << *val << std::endl;
			std::cout << "looking for number 1 in the vector" << std::endl;
			std::vector<int>::const_iterator val2 = ::easyfind(test, 1);
			std::cout << "value2: " << *val2 << std::endl;

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << std::endl << "List tests:" << std::endl;
		std::list<int> test;

		for (int i = 0; i < 10; i++)
			test.push_back(i * 2);

		std::cout << "Elements inside the list: ";
		for (std::list<int>::iterator it = test.begin(); it != test.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		try {
			std::cout << "looking for number 2 in the list" << std::endl;
			std::list<int>::const_iterator val = ::easyfind(test, 2);
			std::cout << "value: " << *val << std::endl;
			std::cout << "looking for number 1 in the list" << std::endl;
			std::list<int>::const_iterator val2 = ::easyfind(test, 1);
			std::cout << "value2: " << *val2 << std::endl;

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << std::endl << "Set tests:" << std::endl;
		std::set<int> test;

		for (int i = 0; i < 10; i++)
			test.insert(i * 2);

		std::cout << "Elements inside the set: ";
		for (std::set<int>::iterator it = test.begin(); it != test.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		try {
			std::cout << "looking for number 2 in the set" << std::endl;
			const std::set<int>::const_iterator val = ::easyfind(test, 2);
			std::cout << "value: " << *val << std::endl;
			std::cout << "looking for number 1 in the set" << std::endl;
			const std::set<int>::const_iterator val2 = ::easyfind(test, 1);
			std::cout << "value2: " << *val2 << std::endl;

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}