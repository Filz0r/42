#pragma once

#include <iostream>
#include <exception>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

class SpanIsFull : public std::exception {
	public:
		const char * what() const throw();
};

class CannotFindSpan : public std::exception {
	public:
		const char * what() const throw();
};

class IndexOutOfBounds : public std::exception {
	public:
		const char * what() const throw();
};

class Span
{
	public:
	    explicit Span(unsigned int capacity);
		Span(const Span &obj);
		Span& operator = (const Span &obj);
		~Span();

		int 			operator[](size_t index) const;

		int 			shortestSpan();
		int 			longestSpan();
		unsigned int	getCapacity() const;
		unsigned int	getOccupied() const;
		unsigned int	getContainerSize() const;
		void			addNumber(int nb);
		void			addNumbers(int numbers);


	private:
		Span();
		unsigned int							capacity;
		unsigned int							occupied;
		std::set<int>							container;
		std::vector<std::set<int>::iterator>	indexCache;
};


std::ostream& operator<<(std::ostream& os, const Span& obj);
