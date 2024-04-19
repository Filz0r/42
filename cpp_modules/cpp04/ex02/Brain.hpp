#pragma once

# include <iostream>

class Brain
{
   public:
      Brain();
      Brain(const Brain &obj);
      ~Brain();
      Brain& operator = (const Brain &obj);

	  std::string *getIdeas();

      private:
  		std::string ideas[100];
};