#pragma once

#include <Animal.hpp>
#include <Brain.hpp>

class Dog: virtual public Animal
{
   public:
      Dog();
      Dog(const Dog &obj);
      ~Dog();
      Dog& operator = (const Dog &obj);

	  void makeSound() const;
	  std::string *getIdeas() const;

   private:
	  Brain *grayMatter;
};