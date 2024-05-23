#include <Data.hpp>
#include <Serialize.hpp>

int	main() {
	Data *test1 = new Data();
	uintptr_t ptrAddr = Serialize::serialize(test1);
	Data *temp = Serialize::deserialize(ptrAddr);

	std::cout << test1;
	std::cout << "Serialized address: " << ptrAddr << std::endl;
	std::cout << "Deserialized obj address: " << &temp << std::endl;
	std::cout << "Deserialized obj" << temp << std::endl;

	delete temp;
	return 0;
}