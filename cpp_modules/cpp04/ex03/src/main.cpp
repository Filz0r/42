#include <IceMateria.hpp>
#include <CureMateria.hpp>
#include <MateriaSource.hpp>
#include <Character.hpp>
#include <Extras.hpp>

int main()
{
	// subject main
//	{
//		IMateriaSource* src = new MateriaSource();
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//
//
//		ICharacter* me = new Character("me");
//
//		AMateria* tmp;
//		tmp = src->createMateria("ice");
//		me->equip(tmp);
//		tmp = src->createMateria("cure");
//		me->equip(tmp);
//
//		ICharacter* bob = new Character("bob");
//		me->use(0, *bob);
//		me->use(1, *bob);
//
//		me->unequip(1); //extra added by be to test unequip
//		delete tmp; // as per the subject requirements unequip doesn't clear memory so we need to clean it manually
//
//		delete bob;
//		delete me;
//		delete src;
//	}

	// my tests 1
//	{
//		IMateriaSource *attacks = new MateriaSource();
//		attacks->learnMateria(new Ice());
//		attacks->learnMateria(new Fire());
//		attacks->learnMateria(new Wind());
//		attacks->learnMateria(new Death());
//
//		IMateriaSource *heals = new MateriaSource();
//		heals->learnMateria(new Cure());
//		heals->learnMateria(new Revive());
//
//		Character *me = new Character("me");
//		me->equip(heals->createMateria("cure"));
//		me->equip(attacks->createMateria("death"));
//		me->equip(attacks->createMateria("fire"));
//		me->equip(heals->createMateria("revive"));
//
//		AMateria *temp = attacks->createMateria("ice");
//
//		me->equip(temp);
//		delete temp;
//		Character *enemy = new Character("enemy");
//		me->use(0, *enemy);
//		me->use(1, *enemy);
//		me->use(2, *enemy);
//		me->use(3, *enemy);
//
//
//		delete attacks;
//		delete heals;
//		delete me;
//		delete enemy;
//	}

	// Materia Source tests
//	{
//		IMateriaSource *materiaSource = new MateriaSource();
//		materiaSource->learnMateria(new Ice());
//		materiaSource->learnMateria(new Fire());
//		materiaSource->learnMateria(new Wind());
//		materiaSource->learnMateria(new Death());
//		materiaSource->learnMateria(new Cure());
//
//		AMateria *temp = materiaSource->createMateria("ice");
//
//		delete temp;
//
//		delete materiaSource;
//	}

	// Deep Copy tests
	{
		IMateriaSource *materiaSource = new MateriaSource();
		materiaSource->learnMateria(new Ice());
		materiaSource->learnMateria(new Fire());

		Character  *t1 = new Character("filipe");
		t1->equip(materiaSource->createMateria("fire"));
		t1->equip(materiaSource->createMateria("ice"));

		// Testing if its possible to create an invalid materia;
		t1->equip(materiaSource->createMateria("asd"));

		// creating some deep copies
		Character t2;
		t2 = *t1;
		Character *t3 = new Character(*t1);

		t1->use(0, t2);
		t1->use(1, t2);
		t1->use(2, t2);
		delete t1; // deleting the t1 pointer, if the copy wasn't deep, trying to use the materias from t3 would cause a segfault;

		t3->use(0, t2);
		delete materiaSource;
		delete t3;
	}

}