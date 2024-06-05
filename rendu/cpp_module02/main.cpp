#include "Warlock.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"
#include "Polymorph.hpp"

int main()
{
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);
	delete polymorph;

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);
	delete fireball;

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");
	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
}