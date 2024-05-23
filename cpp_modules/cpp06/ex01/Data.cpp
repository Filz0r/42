#include <Data.hpp>

Data::Data() : name("default"), value(42), number(0.69f){}

Data::Data(const std::string &_name, int _value, float _number)
	: name(_name), value(_value), number(_number){}


Data::~Data() {}

std::ostream& operator<<(std::ostream& os, const Data& obj) {
	return os << std::endl << "Data object address: " << &obj << std::endl
			  << "Data object name: " << obj.name << std::endl
			  << "Data object value: " << obj.value << std::endl
			  << "Data object number: " << obj.number << std::endl << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Data* obj) {
	return os << std::endl << "Data object address: " << &obj << std::endl
			  << "Data object name: " << obj->name << std::endl
			  << "Data object value: " << obj->value << std::endl
			  << "Data object number: " << obj->number << std::endl << std::endl;
}