#include <iter.hpp>
template<typename T>
void print(T a) {
	std::cout << a << std::endl;
}

int main() {
	int arr1[4] = {1, 2, 3, 4};
	::iter<int>(arr1, 4, print);

	char *str1 = (char *)"this but in vertical mode!";
	::iter<char>(str1, 26, print);

	return 0;
}