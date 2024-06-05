#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::~ATarget() {}
ATarget::ATarget() {}
ATarget::ATarget(const ATarget &obj) { (void)obj; }
ATarget &ATarget::operator=(const ATarget &obj) { (void)obj; return *this;}

const std::string &ATarget::getType() const { return this->type; }
ATarget::ATarget(const std::string &_type) : type(_type) {}

void ATarget::getHitBySpell(const ASpell &fuck) const {
	std::cout << this->getType() << " has been " << fuck.getEffect() << "!" << std::endl;
}