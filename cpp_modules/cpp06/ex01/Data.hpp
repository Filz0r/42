#pragma once

#include <iostream>

struct Data {
	std::string name;
	int 		value;
	float		number;

	Data();
	Data(const std::string &_name, int _value, float _number);
	~Data();
};

std::ostream& operator<<(std::ostream& os, const Data &obj);
std::ostream& operator<<(std::ostream& os, const Data *obj);


