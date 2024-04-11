#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
   public:
      ClapTrap();
      ClapTrap(const std::string &name);
      ClapTrap(const ClapTrap &obj);
      ~ClapTrap();
      ClapTrap& operator = (const ClapTrap &obj);

	  void	attack(const std::string &target);
	  void	takeDamage(unsigned int value);
	  void	beRepaired(unsigned int value);


      private:
	    std::string  name;
      	int hitpoints;
	  	unsigned int energy;
		unsigned int damage;
};