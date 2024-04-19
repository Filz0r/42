#pragma once

#include <Animal.hpp>
#include "Brain.hpp"

class Cat: public Animal
{
   public:
      Cat();
      Cat(const Cat &obj);
      ~Cat();
      Cat& operator = (const Cat &obj);

	  void makeSound() const;
	  std::string *getIdeas() const;


   private:
	  Brain *grayMatter;
};