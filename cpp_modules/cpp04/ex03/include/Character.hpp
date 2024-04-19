#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Interfaces.hpp>

class Character: virtual public ICharacter
{
   public:
      Character();
      Character(const Character &obj);
      ~Character();
      Character& operator = (const Character &obj);

	  void	equip(AMateria *m);
	  void	unequip(int idx);
	  void	use(int idx, ICharacter &target);
	  const std::string &getName();
};

#endif //CHARACTER_HPP