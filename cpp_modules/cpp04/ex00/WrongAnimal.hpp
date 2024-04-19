#pragma once

#include <iostream>

class WrongAnimal
{
   public:
      WrongAnimal();
      WrongAnimal(const std::string &type);
      WrongAnimal(const WrongAnimal &obj);
      virtual ~WrongAnimal();
      WrongAnimal& operator = (const WrongAnimal &obj);

	  void	makeSound();

      protected:
      	std::string type;
};