#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <AMateria.hpp>
#include <Interfaces.hpp>

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	~MateriaSource();
	MateriaSource& operator = (const MateriaSource &obj);

	void learnMateria(AMateria *ptr);
	AMateria *createMateria(const std::string &type);


protected:

//	static size_t currentIndex;

};

#endif // MATERIASOURCE_HPP