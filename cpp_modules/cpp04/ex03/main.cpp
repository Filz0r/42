#include <IceMateria.hpp>
#include <MateriaSource.hpp>

int main()
{
	IMateriaSource *database = new MateriaSource();

	database->learnMateria(new Ice());

	AMateria *test = database->createMateria("ice");

	std::cout << test->getType() << std::endl;

	delete database;
	delete(test);
}