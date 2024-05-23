#include <Tester.hpp>

/**
 * @brief Halts the execution of the program until ENTER is pressed
 * (any other input is ignored)
 */
void	pause() {
	std::cout << "Program paused, press enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Default constructor
 * @param colorCode color code we want to print to the terminal
 */
Color::Color(Code _colorCode) : colorCode(_colorCode) {}

/**
 * @brief default constructor is just a private reset
 */
Color::Color() : colorCode(FG_DEFAULT) {}

/**
 * @brief Destructor does nothing
 */
Color::~Color(){}

/**
 * @brief Getter for the private variable colorCode
 * @return returns an instance of the Color enum the object contains
 */
Code Color::get() const { return this->colorCode; }

/**
 * @brief Overload of the '<<' operator that allows for the given Code enum to
 * print the corresponding color to the terminal.
 *
 *
 * Example usage:
 * std::cout << Color(FG_RED) << "this is red" << Color(FG_DEFAULT) << "this isn't" << std::endl;
 */
std::ostream& operator<<(std::ostream& os, const Color& mod) {
	return os << "\033[" << mod.get() << "m";
}

std::string Tester::goodInputs[] = {
		"42", "-42", "1", "-1", "0",
		"2.0f", "-2.0f",  "10.42f", "-10.42f", "0f",
		"nan", "nanf", "NaN", "NaNf",
		"inf", "-inf", "-inff", "inff",
};

std::string Tester::stringInputs[] = {
		"asdsad",
		"1.0fa12sdsad",
		"1234567865432134760988764321349870743213409876432134980876432134769876432124356754327689645678786435678876567879hjdsakljdsa",
		"information",
		"\"cafe\"",
		"\"asnkdlfa\"",
		"\'asnkdlfa\'",
		"\'\'",
		"1\x1Flol",
		"2\x7Flol",
		"2\x1Alol",
		"3\x3Clol",
		"such a bad\0 test lmao",
};

std::string Tester::charInputs[] = {
		"a",
		"f",
		"z",
		"m",
		"-",
		".",
		"{",
		"c",
		"d",
		"\'",
		"\x1F",
		"\x7F",
		"\x1A",
		"\x3C",
		"\x0",
};

std::string Tester::overflowInputs[] = {
		"1234567865432134760988764321349870743213409876432134980876432134769876432124356754327689645678786435678876567879123313213421212323143432414324632197321732187302179382193821983921809382109830921802013921930921312321321302910392121391209321932193092132193931092391283982109345678908766453564356464643276321347632345678974325769865432457654324798432765435675435674356786432457689689",
		"-12345678654321347609887643213498707432134098764321349808764321347698764321243567543276896456787864356788765678791233132134212123231434324143246321973217321873021793821938219839218093821098309218020139219309213123213213029103921213912093219321930921321939310923912839821097819238713021213992389182302183019233223232",
		"999999999999999999999999999999999999999999999999f",
		"99999999.9999999999999999999999999999999999999999f",
		"01.111111111111111111111111111",
		"99999999.5555555555f",
		"99999999.33333333f",
		"99999999999.33333333f",
		"999999999999.33333333f",
		"99999999999999.33333333f",
		"999999999999999.33333333f",
		"9999999999999999.33333333f",
		"99999999999999999.33333333f",
		"9999999",
		"9999999",
		"99999999",
		"99999999",
		"999999999",
		"9999999999",
		"99999999999",
		"999999999999",
		"9999999999999",
		"99999999999999",
		"999999999999999",
		"9999999999999999",
		"99999999999999999",
		"999999999999999999",

};

void	Tester::goodTests() {
	size_t size;

	std::cout << "First we are going to run some default tests to check that the class works as expected" << std::endl;
	std::cout << Color(FG_LIGHT_YELLOW) << "WARNING:" << Color(FG_DEFAULT) << "If the library is using setprecison to fix the output to a precision of one the numbers might be rounded up from input" << std::endl;
	pause();
	size = sizeof(goodInputs) / sizeof(goodInputs[0]);
	Tester::runTests(goodInputs, size, FG_CYAN, FG_MAGENTA);
}

void	Tester::overflowTests() {
	size_t size;

	std::cout << Color(FG_YELLOW) << "Overflow tests" << Color(FG_DEFAULT) << std::endl;
	std::cout << "Now we are going to run overflow tests, basically trying to break the converter with large numbers" << std::endl;
	std::cout << Color(FG_LIGHT_YELLOW) << "WARNING:" << Color(FG_DEFAULT) << "If the library is using setprecison to fix the output to a precision of one the numbers might be rounded up from input" << std::endl;
	pause();
	size = sizeof(overflowInputs) / sizeof(overflowInputs[0]);
	Tester::runTests(overflowInputs, size, FG_RED, FG_YELLOW);
}

void	Tester::stringTests() {
	size_t size;

	std::cout << Color(FG_MAGENTA) << "String tests" << Color(FG_DEFAULT) << std::endl;
	std::cout << "Now we are going to run tests with strings" << std::endl;
	pause();
	size = sizeof(stringInputs) / sizeof(stringInputs[0]);
	Tester::runTests(stringInputs, size, FG_GREEN, FG_CYAN);
}

void	Tester::charTests() {
	size_t size;

	std::cout << Color(FG_CYAN) << "Char tests" << Color(FG_DEFAULT) << std::endl;
	std::cout << "Now we are going to run tests with chars" << std::endl;
	pause();
	size = sizeof(charInputs) / sizeof(charInputs[0]);
	Tester::runTests(charInputs, size, FG_YELLOW, FG_MAGENTA);
}

void	Tester::runTest(const std::string &input, const Color &barColors, const Color &headerColor) {
	system("clear");
	std::cout << barColors << "-----------------------------" << Color(FG_DEFAULT) << std::endl;
	std::cout << headerColor <<"Input: " << Color(FG_DEFAULT) << "\""  << input << "\"" << std::endl;
	ScalarConverter::convert(input);
	std::cout << barColors << "-----------------------------" << Color(FG_DEFAULT) << std::endl;
	pause();
}

void	Tester::runTests(const std::string inputs[], size_t size, const Color &barColors, const Color &headerColor) {
	for (size_t i = 0; i < size; i++)
		Tester::runTest(inputs[i], barColors, headerColor);
}

void Tester::run() {

	system("clear");
	std::cout << Color(FG_YELLOW) << "Welcome to this amazing tester!" << Color(FG_DEFAULT) << std::endl;
	Tester::goodTests();
	system("clear");
	Tester::overflowTests();
	system("clear");
	Tester::stringTests();
	system("clear");
	Tester::charTests();
}

