#include "Interfaces.hpp"

IMateriaSource::~IMateriaSource() {
	for (size_t i = 0; i < IMateriaSource::maxIndex; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}

ICharacter::~ICharacter() {
	for (size_t i = 0; i < ICharacter::maxIndex; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}