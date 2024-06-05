#pragma once

#include <iostream>

class Warlock {
public:
	Warlock(const std::string &_name, const std::string & _title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void	introduce() const;
	void	setTitle(const std::string &_title);
private:
	std::string name;
	std::string title;

	Warlock();
	Warlock(const Warlock &obj);
	Warlock &operator=(const Warlock &obj);
};