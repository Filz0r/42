#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook {
public:
	SpellBook();
	~SpellBook();
	void	learnSpell(ASpell *spell);
	void	forgetSpell(const std::string &spell);
	ASpell	*createSpell(const std::string &spell);
private:
	std::map<std::string, ASpell *> db;

	SpellBook(const SpellBook &obj);
	SpellBook &operator=(const SpellBook &obj);
};