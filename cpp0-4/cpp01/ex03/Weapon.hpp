#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	public:
		Weapon();
		Weapon(std::string type);
		void setType(const std::string &type);
		const std::string& getType();

	private:
		std::string type;
};

#endif //WEAPON_HPP