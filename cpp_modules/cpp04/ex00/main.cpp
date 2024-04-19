#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	Animal *test = new Animal();
	Animal *duque = new Dog();
	Animal *tareco = new Cat();
	WrongAnimal *test1 = new WrongAnimal();
	WrongAnimal *tarecoFeio = new WrongCat();

	std::cout << "Correct implementation example:" << std::endl << std::endl;
	test->makeSound();
	duque->makeSound();
	tareco->makeSound();

	std::cout << std::endl << "Wrong implementation example:" << std::endl << std::endl;
	test1->makeSound();
	tarecoFeio->makeSound();
	std::cout << std::endl;

	delete test;
	delete duque;
	delete tareco;
	delete tarecoFeio;
	delete test1;
}