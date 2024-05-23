#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
public:
	~ScalarConverter();
	static void convert(const std::string &);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter& operator = (const ScalarConverter &obj);

	static void handleEdgeCase(char *end);
	static void printChar(double nb);
	static void printDouble(double nb);
	static void printInt(double nb);
	static void printFloat(double nb);
};