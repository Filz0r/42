#pragma once

#include <Animal.hpp>

class Dog: virtual public Animal
{
   public:
      Dog();
      Dog(const Dog &obj);
      ~Dog();
      Dog& operator = (const Dog &obj);

	  void makeSound() const;
};