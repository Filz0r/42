#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <iostream>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter();
		virtual const std::string &getName() const = 0;
		virtual void  equip(AMateria *m) = 0;
		virtual void  unequip(int idx) = 0;
		virtual void  use(int idx, ICharacter &target);



	protected:
		std::string			name;
		AMateria			*materias[4];
		int 				hitpoints;
		static const size_t	maxIndex = 4;
		static const int	maxHitponts = 1500;
};

class IMateriaSource {
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;

	protected:
		AMateria *materias[4];
		std::string savedTypes[4];
		static const size_t maxIndex = 4;
};

#endif