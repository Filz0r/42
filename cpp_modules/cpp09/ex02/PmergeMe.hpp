#pragma once

#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <limits>
#include <exception>
#include <algorithm>
#include <ctime>


// can you please get updated on github pretty please
namespace PmergeMe {
	class BadInput : public std::exception {
		private:
			std::string wrongInput;
			BadInput() throw();

		public:
			explicit BadInput(const std::string &input);
			BadInput(const BadInput &obj) throw();
			~BadInput() throw();
			const char *what() const throw();
	};

	class DuplicatedInput : public std::exception {
		private:
			std::string wrongInput;
			DuplicatedInput() throw();

		public:
			explicit DuplicatedInput(const std::string &input);
			DuplicatedInput(const DuplicatedInput &obj) throw();
			~DuplicatedInput() throw();
			const char *what() const throw();
	};

	struct Data {
		private:
			std::vector<long> 	original;
			std::vector<long> 	sorted;
			std::deque<long>	dequeArr;
			std::vector<long>	vectorArr;
			std::string			input;
			Data();

		public:
			const std::string &getInput() const;
			void	printSorted() const;
			void	sortAndPrintVector();
			void	sortAndPrintDeque();
			Data(size_t ac, char **av);
			~Data();
	};

	template<typename T>
	void	print(const T &array);

	template<typename T>
	void mergeInsertionSort(T &arr);

	template<typename T>
	T pairAndSort(T &arr);

	std::ostream  &operator<<(std::ostream  &os, const Data &obj);
}
