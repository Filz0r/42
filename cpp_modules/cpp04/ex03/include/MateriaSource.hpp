#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

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

	private:
		AMateria *materias[4];
		std::string savedTypes[4];
		static const size_t maxIndex = 4;
};

#endif // MATERIASOURCE_HPP