#include "Warlock.hpp"

const std::string &Warlock::getTitle() const{
	return this->title;
}

const std::string &Warlock::getName() const {
	return this->name;
}

void Warlock::introduce() const {
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void Warlock::setTitle(const std::string &_title) {
	this->title = _title;
}

Warlock::Warlock(const std::string &_name, const std::string &_title) : name(_name) , title(_title) {

	std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->getName() << ": My job here is done!" << std::endl;
//	delete this->spellBook;
}

void Warlock::learnSpell(ASpell *spell) {
	this->spellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell) {
	this->spellBook.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string spell, const ATarget &target) {
	ASpell *temp = this->spellBook.createSpell(spell);
	if (temp != NULL)
		temp->launch(target);
}

Warlock::Warlock() {}
Warlock::Warlock(const Warlock &obj) {(void)obj;}
Warlock &Warlock::operator=(const Warlock &obj) {
	(void)obj;
	return *this;
}
