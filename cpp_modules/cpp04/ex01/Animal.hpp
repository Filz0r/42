#pragma once

#include <iostream>

class Animal
{
   public:
      Animal();
      Animal(const std::string &type);
      Animal(const Animal &obj);
      virtual ~Animal();
      Animal& operator = (const Animal &obj);

	  virtual void	makeSound() const;
	  virtual std::string *getIdeas() const;
	  std::string getType();

      protected:
      	std::string type;
};