#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>
#include <Interfaces.hpp>


class AMateria
{
	protected:
		std::string type;
		AMateria();


	public:
		AMateria(const std::string &type);
		const std::string &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use (ICharacter &target);

		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria &obj);
		virtual ~AMateria();
};
#endif