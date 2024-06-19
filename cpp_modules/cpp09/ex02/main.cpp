#include <PmergeMe.hpp>

int main(int ac, char **av) {
	try {
		PmergeMe::Data in(ac, ++av);

		std::cout << "Before: " << in << std::endl;
		in.printSorted();
		in.sortAndPrintVector();
		in.sortAndPrintDeque();

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}