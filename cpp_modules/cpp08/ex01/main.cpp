#include <Span.hpp>

int main() {
	{
		std::cout << "Subject test:" << std::endl;
		Span test(5);

		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);

		try {
			std::cout << test.shortestSpan() << std::endl;
			std::cout << test.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "add numbers test (1000 numbers) :" << std::endl;

		Span test(1000);



		try {
			test.addNumbers(1000);



			std::cout << test.longestSpan() << std::endl;
			std::cout << test.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "add numbers test with exception (1000 numbers):" << std::endl;

		Span test(1000);

		try {
			test.addNumbers(1000);
			test.addNumbers(1000);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "add numbers test(10000 numbers):" << std::endl;

		Span test(10000);

		try {
			test.addNumbers(10000);

//			std::cout << test << std::endl;

			std::cout << test.longestSpan() << std::endl;
			std::cout << test.shortestSpan() << std::endl;

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "add numbers test(100000 numbers):" << std::endl;

		Span test(100000);

		try {
			test.addNumbers(100000); // this takes a long time because its linear and vector is

//			std::cout << test << std::endl;

			std::cout << test.longestSpan() << std::endl;
			std::cout << test.shortestSpan() << std::endl;

		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "mean tests:" << std::endl;

		Span test(10);

		try {
			test.addNumbers(-10);

//			std::cout << test << std::endl << std::endl;

			std::cout << test.longestSpan() << std::endl;
			std::cout << test.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}


	return 0;
}