#pragma once

#include <Classes.hpp>

struct rng {
	rng();
	int generate() ;
};

Base	*generate(void);
void	identify(Base *ptr);
void	identify(Base &ref);