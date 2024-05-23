#pragma once

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <limits>
#include "ScalarConverter.hpp"

/**
 * @brief This enum is used in combination of the Color struct to print dynamic
 * colors to the terminal without using defines
 */
enum Code {
	FG_DEFAULT			= 39,
	FG_BLACK			= 30,
	FG_RED				= 31,
	FG_GREEN			= 32,
	FG_YELLOW			= 33,
	FG_BLUE				= 34,
	FG_MAGENTA			= 35,
	FG_CYAN				= 36,
	FG_LIGHT_GRAY		= 37,
	FG_DARK_GRAY		= 90,
	FG_LIGHT_RED		= 91,
	FG_LIGHT_GREEN		= 92,
	FG_LIGHT_YELLOW		= 93,
	FG_LIGHT_BLUE		= 94,
	FG_LIGHT_MAGENTA	= 95,
	FG_LIGHT_CYAN		= 96,
	FG_WHITE			= 97,
	BG_RED				= 41,
	BG_GREEN			= 42,
	BG_BLUE				= 44,
	BG_DEFAULT			= 49
};


/**
 * @brief This struct is used with an '<<' operator overload to print different
 * colors on the terminal using ASCII codes
 */
struct Color {
	private:
		Code colorCode;
		Color();
	public:
		Color(Code _colorCode);
		~Color();
		Code get() const;
};

std::ostream& operator<<(std::ostream& os, const Color& mod);

/**
 * @brief generic struct used to test the various modules;
 */
struct Tester {
	public:
		static void	run();

	private:
		static void	runTest(const std::string &input, const Color &barColors, const Color &headerColor);
		static void	runTests(const std::string inputs[], size_t size, const Color &barColors, const Color &headerColor);
		static void	goodTests();
		static void	overflowTests();
		static void	stringTests();
		static void	charTests();
		static	std::string goodInputs[];
		static	std::string charInputs[];
		static	std::string stringInputs[];
		static	std::string overflowInputs[];
};