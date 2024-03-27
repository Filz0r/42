#include <iostream>

int main(void)
{
	std::string brain ("HI THIS IS BRAIN");
	std::string *strPTR = &brain;
	std::string &strREF = brain;

	std::cout << "address of variable 'brain': " << &brain << std::endl;
	std::cout << "value of the 'brain' variable: " << brain << std::endl;
	std::cout << "address of variable 'srtPTR': " << strPTR << std::endl;
	std::cout << "value of the pointer 'strPTR' is pointing to: " << *strPTR << std::endl;
	std::cout << "address of variable 'srtREF': " << &strREF << std::endl;
	std::cout << "value of the variable 'srtREF': " << strREF << std::endl;

}