#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstring>

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	(void)obj;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;

	return *this;
}

void ScalarConverter::printChar(double nb) {
	char c = static_cast<char>(nb);

	std::cout << "char: ";
	if (nb < 127 && isprint(c))
		std::cout << "'" << c << "'";
	else if (nb > 127
		|| isinf(nb)
		|| nb == -std::numeric_limits<double>::infinity()
		|| isnan(nb))
		std::cout << "impossible";
	else
		std::cout << "non printable";
	std::cout << std::endl;
}

void ScalarConverter::printInt(double nb) {
	int i = static_cast<int>(nb);

	std::cout << "int: ";
	if (nb < std::numeric_limits<int>::min() ||nb > std::numeric_limits<int>::max() || isnan(nb) || isinf(nb))
		std::cout << "impossible";
	else
		std::cout << i ;
	std::cout << std::endl;
}

void ScalarConverter::printFloat(double nb) {
	float f = static_cast<float>(nb);

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double nb) {
	if (nb == -std::numeric_limits<double>::infinity())
		nb = -std::numeric_limits<double>::infinity();
	else if (nb == std::numeric_limits<double>::infinity())
		nb = std::numeric_limits<double>::infinity();
	std::cout << "double: " << std::fixed << std::setprecision(1) <<  nb << std::endl;
}
/**
 * @brief This method handles the edge case where the input starts as
 * a character, if it doesn't have an length of 1
 * @param end
 */
void ScalarConverter::handleEdgeCase(char *end)
{
	std::string str(end);
	char c = str[0];
	if (str.length() > 1) {
		std::cout << "This is input cannot be converted, goodbye!" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (c < 127 && isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "non printable";
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: "  << std::fixed << std::setprecision(1) <<static_cast<int>(c) << std::endl;
}

void	ScalarConverter::convert(const std::string &toConvert) {

	char *end; // We pass a reference to this variable to strtod
	double d = std::strtod(toConvert.c_str(), &end); // if there's any error,
	// strtod will place the problematic part of the input inside the pointer;
	// We check if toConvert isn't a 0f (0 as a float)
	// and if the first char isn't an 'f' to be sure that it doesn't enter here
	// when we have floating notation of a number as input, the edge case
	// is basically when the input starts with a string value.
	if ((toConvert != "0f" && strlen(end) > 0) && !(strlen(end) != toConvert.length() && strlen(end) == 1 && end[0] == 'f'))
		return ScalarConverter::handleEdgeCase(end);
	size_t	decimalPointPosition = toConvert.find('.');

	ScalarConverter::printChar(d);
	ScalarConverter::printInt(d);
	double temp = d;
	if (decimalPointPosition != std::string::npos) {
		if (decimalPointPosition >= 8)
			temp = std::numeric_limits<float>::infinity();
		ScalarConverter::printFloat(temp);
		if (decimalPointPosition >= 16)
			temp = std::numeric_limits<double>::infinity();
		else
			temp = d;
		ScalarConverter::printDouble(temp);
	} else {
		if (toConvert.length() >= 8) {
			temp = std::numeric_limits<float>::infinity();
		}
		ScalarConverter::printFloat(temp);
		if (toConvert.length() >= 16)
			temp = std::numeric_limits<double>::infinity();
		else
			temp = d;
		ScalarConverter::printDouble(temp);

	}
}