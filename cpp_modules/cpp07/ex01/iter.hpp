#pragma once

#include <iostream>

template<typename T>
void	iter(T *arr, size_t size, void (*cb)(T &a)) {
	for (size_t i = 0; i < size; i++)
			cb(arr[i]);
}