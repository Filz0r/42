#pragma once

#include <ScavTrap.hpp>
#include <FragTrap.hpp>

class DiamondTrap: public ScavTrap, public FragTrap
{
   public:
      DiamondTrap();
      DiamondTrap(const std::string &name);
      DiamondTrap(const DiamondTrap &obj);
      ~DiamondTrap();
      DiamondTrap& operator = (const DiamondTrap &obj);

	  void	attack(const std::string &target);
	  void	whoAmI();

      private:
		std::string name;
};