#include <PmergeMe.hpp>

PmergeMe::BadInput::BadInput(const std::string &input) : wrongInput(input) {}
PmergeMe::BadInput::BadInput(const BadInput &obj) throw() : wrongInput(obj.wrongInput) {}
PmergeMe::BadInput::~BadInput() throw() {}
PmergeMe::BadInput::BadInput() throw() {}
const char *PmergeMe::BadInput::what() const throw() {
	static std::string ret = "ERROR: Invalid input!\nInput: " +  wrongInput;
	return ret.c_str();
}

PmergeMe::DuplicatedInput::DuplicatedInput(const std::string &input) : wrongInput(input) {}
PmergeMe::DuplicatedInput::DuplicatedInput(const DuplicatedInput &obj) throw() : wrongInput(obj.wrongInput) {}
PmergeMe::DuplicatedInput::~DuplicatedInput() throw() {}
PmergeMe::DuplicatedInput::DuplicatedInput() throw() {}
const char *PmergeMe::DuplicatedInput::what() const throw() {
	static std::string ret = "ERROR: Duplicated input!\nInput: " +  wrongInput;
	return ret.c_str();
}

PmergeMe::Data::Data(size_t ac, char **av) {
	// handling bad input
	if (ac < 2)
		throw BadInput("No input was given!");
	else if (ac == 2)
		throw BadInput("I only work with arguments outside of quotes!");

	// reserving space in the vectors to not constantly reallocate memory when they are full
	this->sorted.reserve(ac - 1);
	this->original.reserve(ac - 1);
	this->vectorArr.reserve(ac - 1);

	// Parse stuff
	for (size_t i = 0; i < ac - 1; i++) {
		std::stringstream iss(av[i]);
		std::stringstream sval(av[i]);
		std::string temp, temp2, extraInput;
		long	value;

		iss >> temp;
		// checking if someone is being an ass
		if (!(sval >> value) || sval >> extraInput
			|| value < 0 || value > std::numeric_limits<int>::max())
				throw PmergeMe::BadInput(temp);

		// making the input string look pretty for the print
		if (i == 0 || (i == ac - 1))
			temp2 = temp;
		else
			temp2 = " " + temp;

		// checking if a number already exists and throwing if it does
		std::vector<long>::iterator exists = std::find(this->original.begin(), this->original.end(), value);
		if (exists != this->original.end())
			throw PmergeMe::DuplicatedInput(temp);

		// Push stuff to data structures
		this->input.append(temp2);
		this->sorted.push_back(value);
		this->original.push_back(value);
		this->vectorArr.push_back(value);
		this->dequeArr.push_back(value);
	}

	// sort one vector right away cuz I'm lazy
	std::sort(this->sorted.begin(), this->sorted.end());
}

PmergeMe::Data::~Data() {}
PmergeMe::Data::Data() {}

const std::string &PmergeMe::Data::getInput() const { return this->input; }

// prints the sorted array like the subject shows, again I'm lazy
void	PmergeMe::Data::printSorted() const {
	std::vector<long>::const_iterator it = this->sorted.begin();
	std::cout << "After: ";
	for(; it != this->sorted.end(); ++it) {
		std::cout << *it;
		if (it + 1 != this->sorted.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}


void	PmergeMe::Data::sortAndPrintVector() {
	clock_t start = clock();
	PmergeMe::mergeInsertionSort<std::vector<long> >(this->vectorArr);
	clock_t end = clock();
	double elapsed = double(end - start) * 1000.0/ double(CLOCKS_PER_SEC);
//	print<std::vector<long> >(this->vectorArr);

	std::cout << "Time to process a range of " << this->original.size() << " with std::vector : " << elapsed << " ms"<< std::endl;
}

void	PmergeMe::Data::sortAndPrintDeque() {
	clock_t start = clock();
	PmergeMe::mergeInsertionSort<std::deque<long> >(this->dequeArr);
	clock_t end = clock();
	double elapsed = double(end - start)  * 1000.0 / double(CLOCKS_PER_SEC);
//	print<std::deque<long> >(this->dequeArr);

	std::cout << "Time to process a range of " << this->original.size() << " with std::deque : " << elapsed << " ms"<< std::endl;
}

template<typename T>
void	PmergeMe::print(const T &array) {
	typename T::const_iterator it = array.begin();

	std::cout << "Dataset: ";
	for (; it != array.end(); ++it) {
		std::cout << *it;
		if (it + 1 != array.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}


// creates a new container where the largest elements are sorted
// using the following logic eg:
// Original container: 4 1 32 3
// Paired container: 1 4 3 32
// if the container has a odd length the final element will be left alone
template<typename T>
T	PmergeMe::pairAndSort(T &arr) {
	T pairs;

	for (size_t i = 0; i < arr.size(); i += 2) {
		if (i + 1 < arr.size()) {
			pairs.push_back(std::min(arr[i], arr[i + 1]));
			pairs.push_back(std::max(arr[i], arr[i + 1]));
		} else {
			pairs.push_back(arr[i]);
		}
	}
	return pairs;
}

template<typename T>
void	PmergeMe::mergeInsertionSort(T &arr) {
	if (arr.size() <= 1)
		return ;
	// First we pair the big and small numbers side by side
	T pairs = PmergeMe::pairAndSort(arr);

	T larger;
	// Now we add the large part of the container to the larger container
	for (size_t i = 1; i < pairs.size(); i += 2)
		larger.push_back(pairs[i]);
	// Recursion until the larger container is sorted
	PmergeMe::mergeInsertionSort(larger);
	// Finally we insert the sorted elements into the larger container
	for (size_t i = 0; i < pairs.size(); i += 2) {
		// upper_bound looks for the iterator position where we can insert the element
		// in a sorted container without messing with the already sorted container
		// if no element smaller than pairs[i] is found it adds the number to the end
		// of the container
		larger.insert(std::upper_bound(larger.begin(), larger.end(), pairs[i]),
					  pairs[i]);
	}
	arr = larger;
}


// operators give me lazy ideas
std::ostream	&PmergeMe::operator<<(std::ostream &os, const PmergeMe::Data &obj) {
	return os << obj.getInput();
}