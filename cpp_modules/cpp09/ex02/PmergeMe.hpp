#pragma once

#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <limits>
#include <exception>
#include <algorithm>
#include <ctime>

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

	struct Input {
		private:
			std::vector<long> 	original;
			std::vector<long> 	sorted;
			std::deque<long>	dequeArr;
			std::vector<long>	vectorArr;
			std::string			_input;
			Input();
			Input(const Input &obj);
			Input &operator=(const Input &obj);

		public:
			const std::string &getInput() const;
			void	printSorted() const;
			void	sortAndPrintVector();
			void	sortAndPrintDeque();
			Input(size_t ac, char **av);
			~Input();
	};
	template<typename T>
	void	mergeSort(T &array);
	template<typename T>
	void	merge(T &left,  T &right, T &array);
	template<typename T>
	void	print(const T &array);

	std::ostream  &operator<<(std::ostream  &os, const Input &obj);
}
