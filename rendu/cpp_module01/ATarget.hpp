#pragma once

#include <iostream>

class ASpell;

class ATarget {
protected:
	std::string type;
private:
	ATarget();
	ATarget(const ATarget &obj);
	ATarget &operator=(const ATarget &obj);
public:
	const std::string &getType() const;
	ATarget(const std::string &_type);
	virtual ~ATarget();
	void	getHitBySpell(const ASpell &fuck) const;
	virtual ATarget *clone() const = 0;
};