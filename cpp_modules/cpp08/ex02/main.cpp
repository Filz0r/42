#include <MutantStack.hpp>

int main() {
	MutantStack<int> test;

	for (int i = 0; i < 10; i++)
		test.push(i * 2);
	MutantStack<int>::iterator  it = test.begin();
	MutantStack<int>::const_iterator  cit = test.begin();

	for (; it != test.end(); ++it) {
		std::cout << "Before: " << *it << std::endl;
		*it = *it / 2;
		std::cout << "After: " << *it << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	std::cout << "Before pop Size: " << test.size() << std::endl;
	test.pop();
	test.pop();
	test.pop();
	std::cout << "Size after: " << test.size() << std::endl;

	for (; cit != test.end(); ++cit) {
		std::cout << *cit << std::endl;
//		*cit = *cit / 2; // <- Doesn't compile because the iterator is const
	}

	return 0;
}