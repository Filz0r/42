#ifndef CUREMATERIA_HPP
#define CUREMATERIA_HPP

#include <Interfaces.hpp>

class Cure: virtual public AMateria
{
public:
	Cure();
	Cure(const Cure &obj);
	~Cure();
	Cure& operator = (const Cure &obj);

	void use(ICharacter &target);
	AMateria *clone() const;

	size_t	getValue() const;


protected:
	void	doDamage(ICharacter &target) const;
	void	restoreHitpoints(ICharacter &target) const;
};

#endif // CUREMATERIA_HPP