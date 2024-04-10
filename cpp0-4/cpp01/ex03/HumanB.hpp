#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <Weapon.hpp>

class HumanB {
	private:
		Weapon		*weapon;
		std::string	name;

	public:
		HumanB(const std::string &name);
		void giveWeapon(Weapon &weapon);
		void attack();
};

#endif //HUMANB_HPP