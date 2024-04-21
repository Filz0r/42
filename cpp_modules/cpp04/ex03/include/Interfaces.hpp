#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;
		size_t 		value;
		AMateria();
//		virtual void doDamage(ICharacter &target) const = 0;
//		virtual void restoreHitpoints(ICharacter &target) const = 0;


	public:
		AMateria(const std::string &type);
		const std::string &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

		virtual size_t getValue() const = 0;

		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria &obj);
		virtual ~AMateria();
};

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual const std::string &getName() const = 0;
		virtual void  equip(AMateria *m) = 0;
		virtual void  unequip(int idx) = 0;
		virtual void  use(int idx, ICharacter &target) = 0;
};

//		virtual void changeHitpoints(size_t value, bool isDamage) = 0;
//		virtual int getHitpoints() const = 0;

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif