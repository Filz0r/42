#include "ASpell.hpp"
#include "ATarget.hpp"

const std::string &ASpell::getName() const {
	return this->name;
}

const std::string &ASpell::getEffect() const {
	return this->effects;
}

ASpell::ASpell(const std::string &_name, const std::string &_effects) : name(_name), effects(_effects) {}

ASpell::~ASpell() {}
ASpell::ASpell() {}
ASpell::ASpell(const ASpell &obj) {(void)obj;}

ASpell &ASpell::operator=(const ASpell &obj) {
	(void)obj;
	return *this;
}

void ASpell::launch(const ATarget &u_fucked) const {
	u_fucked.getHitBySpell(*this);
}