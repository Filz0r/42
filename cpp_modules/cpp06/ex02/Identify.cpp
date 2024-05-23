#include <Identify.hpp>

#include <unistd.h>
#include <ctime>
#include <cstdlib>

rng::rng() {
	srand(getpid() + time(NULL));
}

int rng::generate() {
	return rand() % 3 + 1;
}

static rng r;

Base	*generate( void ) {

	switch (r.generate()) {
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
		default:
			return new A();
	}
}

void identify(Base *ptr) {
	A *type1 = NULL;
	B *type2 = NULL;
	C *type3 = NULL;

	if ((type1 = dynamic_cast<A *>(ptr)) != NULL) {
		std::cout << "The pointer is an element off the A class" << std::endl;
	} else if ((type2 = dynamic_cast<B *>(ptr)) != NULL) {
		std::cout << "The pointer is an element off the B class" << std::endl;
	} else if ((type3 = dynamic_cast<C *>(ptr)) != NULL) {
		std::cout << "The pointer is an element off the C class" << std::endl;
	}
}

void identify(Base &obj) {
	A type1;
	B type2;
	C type3;
	int type = -1;

	try {
		type1 = dynamic_cast<A &>(obj);
		type = 1;
	} catch (std::exception &e) {}
	if (type == -1) {
		try {
			type2 = dynamic_cast<B &>(obj);
			type = 2;
		} catch (std::exception &e) {}
	}
	if (type == -1) {
		try {
			type3 = dynamic_cast<C &>(obj);
			type = 3;
		} catch (std::exception &e) {}
	}



	switch (type) {
		case 1:
			std::cout << "The object is off the A class" << std::endl;
			break;
		case 2:
			std::cout << "The object is off the B class" << std::endl;
			break;
		case 3:
			std::cout << "The object is off the C class" << std::endl;
			break;
		default:
			std::cout << "Im never gonna be called" << std::endl;
			break;
	}
}