#include <MutantStack.hpp>

int main() {
	MutantStack<int> test;

	for (int i = 0; i < 10; i++)
		test.push(i * 2);
	MutantStack<int>::iterator  it = test.begin();

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

	std::cout << "------Const Iterator tests------" << std::endl;
	MutantStack<int>::const_iterator  cit = test.begin();

	for (; cit != test.end(); ++cit) {
		std::cout << *cit << std::endl;
//		*cit = *cit / 2; // <- Doesn't compile because the iterator is const
	}

	{
		std::cout << "------SUBJECT TESTS------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "------------" << std::endl;
	}

	return 0;
}