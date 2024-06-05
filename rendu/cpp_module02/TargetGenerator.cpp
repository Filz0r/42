#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget *target) {
	this->db.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(const std::string &target) {
	this->db.erase(target);
}

ATarget	*TargetGenerator::createTarget(const std::string &target) {
	std::map<std::string, ATarget *>::iterator it = this->db.begin();
	for (;it != this->db.end(); ++it)
	{
		if (it->first == target) {
			return it->second;
		}
	}
	return NULL;
}

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}
TargetGenerator::TargetGenerator(const TargetGenerator &obj) {(void)obj;}
TargetGenerator &TargetGenerator::operator=(const TargetGenerator &obj) {
	(void)obj;
	return *this;
}