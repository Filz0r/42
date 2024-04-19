#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Interfaces.hpp>

class Character: virtual public ICharacter
{
   public:
      Character();
      Character(const std::string &_name);
      Character(const Character &obj);
      ~Character();
      Character& operator = (const Character &obj);

	  void	equip(AMateria *m);
	  void	unequip(int idx);
	  void	use(int idx, ICharacter &target);
	  const std::string &getName() const;

	  int getHitpoints() const;
	  void changeHitpoints(size_t value, bool isDamage);

   private:
		std::string			name;
		AMateria			*materias[4];
		int 				hitpoints;
		static const size_t	maxIndex = 4;
		static const int	maxHitponts = 1500;

};

#endif //CHARACTER_HPP