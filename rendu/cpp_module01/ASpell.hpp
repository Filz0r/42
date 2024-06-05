#pragma once

#include <iostream>

class ATarget;

class ASpell {

private:
	ASpell();
	ASpell(const ASpell &obj);
	ASpell &operator=(const ASpell &obj);
protected:
	std::string name;
	std::string effects;


public:
	ASpell(const std::string &_name, const std::string &_effects);
	const std::string &getName() const;
	const std::string &getEffect() const;
	void	launch(const ATarget &u_fucked) const;
	virtual ~ASpell();
	virtual ASpell *clone() const = 0;
};