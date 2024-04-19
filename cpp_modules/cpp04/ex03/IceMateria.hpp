#ifndef ICEMATERIA_HPP
#define ICEMATERIA_HPP

#include <AMateria.hpp>

class Ice: virtual public AMateria
{
   public:
      Ice();
      Ice(const Ice &obj);
      ~Ice();
      Ice& operator = (const Ice &obj);

	  void use(ICharacter &target);
	  AMateria *clone() const;


};

#endif