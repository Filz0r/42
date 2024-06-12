#include <Identify.hpp>

int main() {
	Base *test = generate();
	Base *test1 = generate();
	Base *test2 = generate();
	identify(test);
	identify(test1);
	identify(test2);

	identify(*test);
	identify(*test1);
	identify(*test2);

	delete test;
	delete test1;
	delete test2;
}