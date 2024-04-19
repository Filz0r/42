#include <IceMateria.hpp>
#include <CureMateria.hpp>
#include <MateriaSource.hpp>
#include <Character.hpp>

int main()
{
	IMateriaSource *database = new MateriaSource();
	database->learnMateria(new Ice());
	database->learnMateria(new Cure());


	AMateria *test = database->createMateria("ice");
	Character *me = new Character("me");
	me->equip(test);
	me->equip(database->createMateria("cure"));

	Character *enemy = new Character("enemy");
	ICharacter *enemy2 = new Character(*enemy);
	Character me2;
	me2 = *me;

	Character me3(me2);

	me->use(0, *enemy);
	me->use(1, *enemy2);
	me->use(0, me2);
	me2.use(1, *me);
	me2.use(0, *enemy);
	me2.use(0, *enemy2);
	me3.use(0, *enemy2);


	delete database;
	delete me;
	delete enemy;
	delete enemy2;
}