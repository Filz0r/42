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
}

void Warlock::learnSpell(ASpell *spell) {
	this->db.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	Warlock::forgetSpell(std::string spell) {
	std::map<std::string, ASpell *>::iterator it = this->db.begin();
	for (;it != this->db.end(); ++it)
	{
		if (it->first == spell) {
			delete it->second;
			this->db.erase(it);
			return ;
		}
	}
}

void	Warlock::launchSpell(std::string spell, const ATarget &target) {
	std::map<std::string, ASpell *>::iterator it = this->db.begin();
	for (;it != this->db.end(); ++it)
	{
		if (it->first == spell) {
			target.getHitBySpell(*(it->second));
			return ;
		}
	}
}

Warlock::Warlock() {}
Warlock::Warlock(const Warlock &obj) {(void)obj;}
Warlock &Warlock::operator=(const Warlock &obj) {
	(void)obj;
	return *this;
}

//int main()
//{
//	Warlock const richard("Richard", "Mistress of Magma");
//	richard.introduce();
//	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
//
//	Warlock* jack = new Warlock("Jack", "the Long");
//	jack->introduce();
//	jack->setTitle("the Mighty");
//	jack->introduce();
//
//	delete jack;
//
//	return (0);
//}
