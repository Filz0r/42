#include "SpellBook.hpp"

void SpellBook::learnSpell(ASpell *spell) {
	this->db.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(const std::string &spell) {
	this->db.erase(spell);
}

ASpell	*SpellBook::createSpell(const std::string &spell) {
	std::map<std::string, ASpell *>::iterator it = this->db.begin();
	for (;it != this->db.end(); ++it)
	{
		if (it->first == spell) {
			return it->second;
		}
	}
	return NULL;
}

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {
//	for(auto it = db.begin(); it != db.end(); ++it) {
//		delete it->second;
//	}
//	db.clear();
}
SpellBook::SpellBook(const SpellBook &obj) {(void)obj;}
SpellBook &SpellBook::operator=(const SpellBook &obj) {
	(void)obj;
	return *this;
}