#include <IceMateria.hpp>
#include <CureMateria.hpp>
#include <MateriaSource.hpp>
#include <Character.hpp>
#include <Extras.hpp>

int main()
{
	IMateriaSource *attacks = new MateriaSource();
	attacks->learnMateria(new Ice());
	attacks->learnMateria(new Fire());
	attacks->learnMateria(new Wind());
	attacks->learnMateria(new Death());

	IMateriaSource *heals = new MateriaSource();
	heals->learnMateria(new Cure());
	heals->learnMateria(new Revive());

	Character *me = new Character("me");
//	me->equip(test);
	me->equip(heals->createMateria("cure"));
	me->equip(attacks->createMateria("death"));
	me->equip(attacks->createMateria("fire"));
	me->equip(heals->createMateria("revive"));
//
	AMateria *temp = attacks->createMateria("ice");

	me->equip(temp);
	delete temp;
	Character *enemy = new Character("enemy");
//	ICharacter *enemy2 = new Character(*enemy);
//	Character me2;
//	me2 = *me;
//
//	Character me3(me2);
//
	me->use(0, *enemy);
	me->use(1, *enemy);
	me->use(2, *enemy);
	me->use(3, *enemy);
//	me->use(1, *enemy2);
//	me->use(0, me2);
//	me2.use(1, *me);
//	me2.use(0, *enemy);
//	me2.use(0, *enemy2);
//	me3.use(0, *enemy2);


	delete attacks;
	delete heals;
	delete me;
	delete enemy;
//	delete enemy2;
}