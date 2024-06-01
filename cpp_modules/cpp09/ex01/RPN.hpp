#pragma once

#include <iostream>
#include <sstream>
#include <exception>
#include <list> // our underlying container
#include <stack> // To grab the adapter and create a "custom" container
// RTFM: https://en.cppreference.com/w/cpp/container/stack

bool	isOperator(char c);
void	replaceWs(std::string &str);
double	doTheMath(const std::string &op, double a, double b);

class RPN
{
	typedef std::stack<double, std::list<double> > numberStack;

	public:
	// constructor / destructor
      explicit RPN(const std::string &_input);
      ~RPN();

	// Exceptions
		class BadInput : public std::exception {
		public:
			const char *what() const throw();
		};

	private:
	// canonical orthodox stuff
		RPN();
		RPN(const RPN &obj);
		RPN& operator = (const RPN &obj);

	// Attributes
		numberStack 	numbers;
};