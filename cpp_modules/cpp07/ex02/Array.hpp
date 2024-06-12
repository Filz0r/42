#pragma once

#include <iostream>
#include <exception>



template<typename T>
class Array {
	public:
		// Constructors and destructor
		Array() : capacity(1), array(new T[1]) {};

		Array(size_t _size) : capacity(_size), array(new T[_size]) {};

		Array(const Array &obj) {
			this->array = new T[obj.size()];
			this->capacity = obj.size();
			for (size_t i = 0; i < obj.size(); i++)
				this->array[i] = obj[i];
		};

		~Array() { delete[] array; };

		class IndexOutOfBounds : public std::exception {
		public:
			const char	*what() const throw() {
				return "Error: Index out of bounds!";
			};
		};
		// Operators
		Array &operator=(const Array &obj) {
			if (this != &obj)
			{
				delete[] this->array;
				this->array = new T[obj.size()];
				this->capacity = obj.size();
				for (size_t i = 0; i < obj.size(); i++)
					this->array[i] = obj[i];
			}
			return *this;
		};

		T &operator[](size_t index) const {
			if (index > this->capacity - 1)
				throw Array::IndexOutOfBounds();
			else
				return this->array[index];
		};

		// Methods
		size_t size() const{
			return this->capacity;
		};


	private:
		size_t	capacity;
		T		*array;
};