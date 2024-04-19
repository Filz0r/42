#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
int main()
{
	Animal *animals[10];

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "\t\tARRAY TESTS" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << "-------------------------------------------" << std::endl;
		animals[i]->makeSound();
		std::cout << "-------------------------------------------" << std::endl;
	}

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "\t\tCOPY TESTS" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	Cat *test = new Cat();
	Cat *copy = new Cat(*test);
	Cat t1 = Cat();
	std::cout << "-------------------------------------------" << std::endl;
	Cat t2 = Cat(t1);
	std::cout << "-------------------------------------------" << std::endl;
	Cat t3 = t1;
	std::cout << "-------------------------------------------" << std::endl;
	Cat t4;

	t4 = t1;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << t1.getIdeas() << std::endl;
	std::cout << t1.getIdeas() << std::endl;
	std::cout << t2.getIdeas() << std::endl;
	std::cout << t3.getIdeas() << std::endl;
	std::cout << t4.getIdeas() << std::endl;
	std::cout << &t1 << std::endl;
	std::cout << &t2 << std::endl;
	std::cout << &t3 << std::endl;
	std::cout << &t4 << std::endl;


	std::cout << test->getIdeas() << std::endl;
	std::cout << copy->getIdeas() << std::endl;
	std::cout << &copy << std::endl;
	std::cout << &test << std::endl;
	delete test;
	delete copy;
	std::cout << "-------------------------------------------" << std::endl;

	for(int i = 0; i < 10; i++)
		delete animals[i];
}