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

PmergeMe::Input::Input(size_t ac, char **av) {
	this->original.reserve(3000);

	for (size_t i = 0; i < ac - 1; i++) {
		std::stringstream iss(av[i]);
		std::stringstream sval(av[i]);
		std::string temp, temp2, extraInput;
		long	value;

		iss >> temp;
		if (!(sval >> value) || sval >> extraInput
			|| value < 0 || value > std::numeric_limits<int>::max())
				throw PmergeMe::BadInput(temp);
		if (i == 0 || (i == ac - 1))
			temp2 = temp;
		else
			temp2 = " " + temp;
		std::vector<long>::iterator exists = std::find(this->original.begin(), this->original.end(), value);
		if (exists != this->original.end())
			throw PmergeMe::DuplicatedInput(temp);

		this->_input.append(temp2);
		this->original.push_back(value);
		this->sorted.push_back(value);
		this->vectorArr.push_back(value);
		this->dequeArr.push_back(value);
	}

	std::sort(this->sorted.begin(), this->sorted.end());
}

PmergeMe::Input::~Input() {}
PmergeMe::Input::Input() {}

const std::string &PmergeMe::Input::getInput() const { return this->_input; }

void	PmergeMe::Input::printSorted() const {
	std::vector<long>::const_iterator it = this->sorted.begin();
	std::cout << "After: ";
	for(; it != this->sorted.end(); ++it) {
		std::cout << *it;
		if (it + 1 != this->sorted.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe::mergeSort(T &array) {
	size_t	len = array.size();
	if (len <= 1)
		return ;

	size_t	middle = len / 2;
	T left(array.begin(), array.begin() + middle);
	T right(array.begin() + middle, array.end());

	PmergeMe::mergeSort(left);
	PmergeMe::mergeSort(right);
	PmergeMe::merge(left, right, array);
}

template<typename T>
void	PmergeMe::merge(T &left, T &right, T &array) {
	size_t leftSize = array.size() / 2;
	size_t rightSize = array.size() - leftSize;
	size_t i = 0, r = 0, l = 0;

	while(l < leftSize && r < rightSize) {
		if (left[l] < right[r]) {
			array[i++] = left[l++];
		} else {
			array[i++] = right[r++];
		}
	}
	while (l < leftSize) {
		array[i++] = left[l++];
	}
	while (r < rightSize) {
		array[i++] = right[r++];
	}
}

void	PmergeMe::Input::sortAndPrintVector() {
	clock_t start = clock();
	PmergeMe::mergeSort<std::vector<long> >(this->vectorArr);
	clock_t end = clock();
	double elapsed = double(end - start) * 1000.0/ double(CLOCKS_PER_SEC);
//	print<std::vector<long> >(this->vectorArr);

	std::cout << "Time to process a range of " << this->vectorArr.size() << " with std::vector : " << elapsed << " ms"<< std::endl;
}

void	PmergeMe::Input::sortAndPrintDeque() {
	clock_t start = clock();
	PmergeMe::mergeSort<std::deque<long> >(this->dequeArr);
	clock_t end = clock();
	double elapsed = double(end - start)  * 1000.0 / double(CLOCKS_PER_SEC);
	//	print<std::deque<long> >(this->dequeArr);

	std::cout << "Time to process a range of " << this->dequeArr.size() << " with std::deque : " << elapsed << " ms"<< std::endl;

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

std::ostream	&PmergeMe::operator<<(std::ostream &os, const PmergeMe::Input &obj) {
	return os << obj.getInput();
}