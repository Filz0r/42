#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock {
public:
	Warlock(const std::string &_name, const std::string & _title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void	introduce() const;
	void	setTitle(const std::string &_title);
	void	learnSpell(ASpell *spell);
	void	forgetSpell(const std::string spell);
	void	launchSpell(const std::string spell, const ATarget &target);
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell *> db;

	Warlock();
	Warlock(const Warlock &obj);
	Warlock &operator=(const Warlock &obj);
};