#include "Span.hpp"

const char *SpanIsFull::what() const throw() {
	return "Error: The span object is already at capacity!";
}

const char *CannotFindSpan::what() const throw() {
	return "Error: Cannot find a span with the current elements of the container!";
}

const char *IndexOutOfBounds::what() const throw() {
	return "Error: Index out of bounds!";
}

Span::Span(unsigned int _capacity) : capacity(_capacity), occupied(0) {
	indexCache.reserve(_capacity);
}
Span::Span() : capacity(0), occupied(0) {}

Span::~Span() {
//	std::cout << "Span Destructor called" << std::endl;
	this->container.clear();
	this->indexCache.clear();
}

Span::Span(const Span &obj) {
	this->indexCache.reserve(obj.getCapacity());
	for (std::vector<std::_Rb_tree_const_iterator<int> >::const_iterator it = obj.indexCache.begin(); it != obj.indexCache.end(); ++it)
		this->addNumber(**it);
	this->occupied = obj.getOccupied();
	this->capacity = obj.getCapacity();
//	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &obj)
{
	if (this != &obj) {
		this->indexCache.reserve(obj.getCapacity());
		for (std::vector<std::_Rb_tree_const_iterator<int> >::const_iterator it = obj.indexCache.begin(); it != obj.indexCache.end(); ++it)
			this->addNumber(**it);
		this->occupied = obj.getOccupied();
		this->capacity = obj.getCapacity();
	}
//	std::cout << "Span copy assignment operator called" << std::endl;
	return *this;
}

void	Span::addNumber(int nb) {
	if (this->occupied + 1 > this->capacity)
		throw SpanIsFull();
	std::pair<std::set<int>::iterator, bool> ret = this->container.insert(nb);
	if (ret.second) {
		this->indexCache.push_back(ret.first);
		this->occupied++;
	}
}

void	Span::addNumbers(int numbers) {
	size_t temp = std::abs(numbers);
	if (this->container.size() + temp > this->capacity)
		throw SpanIsFull();

	std::vector<int> numbs(temp);
	for (int i = 0; i < (int)temp; ++i)
		numbs[i] = numbers < 0 ? -i : i;
	for (std::vector<int>::iterator it = numbs.begin(); it != numbs.end(); ++it) {
		std::pair<std::set<int>::iterator, bool> ret = this->container.insert(*it);
		if (ret.second) {
			this->indexCache.push_back(ret.first);
			this->occupied++;
		}
	}
}

int Span::shortestSpan() {
	if (this->container.size() < 2 || this->capacity < 2 || this->occupied < 2)
		throw CannotFindSpan();

	std::set<int>::iterator it = this->container.begin();
	std::set<int>::iterator prev = it;
	++it;
	int minSpan = *it - *prev;
	for(; it != this->container.end(); ++it) {
		int span = *it - *prev;
		if (span < minSpan)
			minSpan = span;
		prev = it;
	}

	return minSpan;
}

int Span::longestSpan() {
	if (this->container.size() < 2 || this->capacity < 2 || this->occupied < 2)
		throw CannotFindSpan();

	int smallestElement = *this->container.begin();
	int largestElement = *this->container.rbegin();

	return largestElement - smallestElement;
}

unsigned int	Span::getCapacity() const { return this->capacity; }
unsigned int	Span::getOccupied() const { return this->occupied; }
unsigned int	Span::getContainerSize() const { return this->container.size(); }

int Span::operator[](size_t index) const{
	if (index >= this->occupied)
		throw IndexOutOfBounds();
	return *this->indexCache[index];
}

std::ostream 	&operator<<(std::ostream  &os, const Span &obj) {
	std::stringstream response;
	response << "Span object details: " << std::endl;
	response << "address: " << &obj << std::endl;
	response << "capacity: " << obj.getCapacity() << std::endl;
	response << "used: " << obj.getOccupied() << std::endl;
	response << "size: " << obj.getContainerSize() << std::endl;
	response << "Elements of the set:" << std::endl;
	for (unsigned int i = 0; i < obj.getOccupied(); i++)
		response << "container[" << i << "]: " << obj[(size_t)i] << std::endl;
	return os << response.str();
}