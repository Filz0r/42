#pragma once

#include <algorithm>
#include <exception>

class NotFound : public std::exception {
	public:
		const char *what() const throw () {
			return "Error: Element not found inside the container!";
		}
};

template <typename T, typename ValueType>
typename T::const_iterator easyfind(const T &container, ValueType toFind) {
	typename T::const_iterator element = std::find(container.begin(), container.end(), toFind);
	if (element == container.end())
		throw NotFound();
	return element;
}