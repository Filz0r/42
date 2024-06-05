#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class TargetGenerator {
public:
	TargetGenerator();
	~TargetGenerator();
	void	learnTargetType(ATarget *target);
	void	forgetTargetType(const std::string &target);
	ATarget	*createTarget(const std::string &target);
private:
	std::map<std::string, ATarget *> db;

	TargetGenerator(const TargetGenerator &obj);
	TargetGenerator &operator=(const TargetGenerator &obj);
};