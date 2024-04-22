#include <MateriaSource.hpp>

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < MateriaSource::maxIndex; i++)
	{
		this->materias[i] = NULL;
		this->savedTypes[i].clear();
	}
	std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < MateriaSource::maxIndex; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
	std::cout << "MateriaSource Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
	*this = obj;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;

if (this != &obj)
	{
		for (size_t i = 0; i < MateriaSource::maxIndex; i++)
		{
			if (this->materias[i])
			{
				delete this->materias[i];
				this->materias[i] = NULL;
			}
			if (obj.materias[i])
			{
				this->materias[i] = obj.materias[i]->clone();
				this->savedTypes[i] = obj.savedTypes[i];
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *ptr) {
	if (!ptr)
		return;

	for (size_t i = 0; i < MateriaSource::maxIndex; i++)
	{
		if (this->savedTypes[i].empty() && this->savedTypes[i] == ptr->getType())
		{
			std::cout << "MateriaSource has already learned the Materia of type: " << ptr->getType() << std::endl;
			delete ptr;
			return ;
		}
	}

	for (size_t i = 0; i < MateriaSource::maxIndex; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = ptr->clone();
			this->savedTypes[i] = ptr->getType();
			std::cout << "MateriaSource has learned the Materia of type: " << ptr->getType() << std::endl;
			delete ptr;
			return ;
		}
	}
	std::cout << "Error learning the a new materia of type: " << ptr->getType() << std::endl;
	delete ptr;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (size_t i = 0; i < MateriaSource::maxIndex; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return NULL;
}