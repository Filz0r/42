#ifndef ICEMATERIA_HPP
#define ICEMATERIA_HPP

#include <Interfaces.hpp>

class Ice: virtual public AMateria
{
   public:
      Ice();
      Ice(const Ice &obj);
      ~Ice();
      Ice& operator = (const Ice &obj);

	  void use(ICharacter &target);
	  AMateria *clone() const;

	  size_t	getValue() const;


   protected:
		void	doDamage(ICharacter &target) const;
		void	restoreHitpoints(ICharacter &target) const;

};

#endif