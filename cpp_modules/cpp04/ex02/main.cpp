#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

int main()
{
//	Animal a;
//	Animal *b = new Animal();
	Dog *dog = new Dog();
	Cat *cat = new Cat();


	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}