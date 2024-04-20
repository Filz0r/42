#ifndef EXTRAS_HPP
#define EXTRAS_HPP

#include <Interfaces.hpp>

class Fire: virtual public AMateria
{
public:
	Fire();
	Fire(const Fire &obj);
	~Fire();
	Fire& operator = (const Fire &obj);

	void use(ICharacter &target);
	AMateria *clone() const;

	size_t	getValue() const;


protected:
	void	doDamage(ICharacter &target) const;
	void	restoreHitpoints(ICharacter &target) const;

};



class Wind: virtual public AMateria
{
public:
	Wind();
	Wind(const Wind &obj);
	~Wind();
	Wind& operator = (const Wind &obj);

	void use(ICharacter &target);
	AMateria *clone() const;

	size_t	getValue() const;


protected:
	void	doDamage(ICharacter &target) const;
	void	restoreHitpoints(ICharacter &target) const;

};

class Revive: virtual public AMateria
{
public:
	Revive();
	Revive(const Revive &obj);
	~Revive();
	Revive& operator = (const Revive &obj);

	void use(ICharacter &target);
	AMateria *clone() const;

	size_t	getValue() const;


protected:
	void	doDamage(ICharacter &target) const;
	void	restoreHitpoints(ICharacter &target) const;

};

class Death: virtual public AMateria
{
public:
	Death();
	Death(const Death &obj);
	~Death();
	Death& operator = (const Death &obj);

	void use(ICharacter &target);
	AMateria *clone() const;

	size_t	getValue() const;


protected:
	void	doDamage(ICharacter &target) const;
	void	restoreHitpoints(ICharacter &target) const;

};


#endif //EXTRAS_HPP