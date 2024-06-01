#include <cstdlib>
#include "RPN.hpp"

bool isOperator(char c) {
	return c == '+' || c == '*' || c == '-' || c == '/';
}

bool	isAlphaString(const std::string &str) {
	std::string::const_iterator it = str.begin();
	for (; it != str.end(); ++it) {
		if (!isdigit(*it) && !isOperator(*it) && *it != ' ') {
			return true;
		}
	}
	return false;
}

double	doTheMath(const std::string &op, double a, double b) {
	if (op == "+")
		return a + b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return b / a;
	else if (op == "-")
		return b - a;
	else
		throw RPN::BadInput();
}

void	replaceWs(std::string &str)
{
	std::string::iterator it = str.begin();

	while (it != str.end()) {
		if (std::isspace(*it)) {
			*it = ' ';
		}
		++it;
	}
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &obj) { (void)obj; }

RPN& RPN::operator=(const RPN &obj) {
	(void)obj;
	return *this;
}

RPN::RPN(const std::string &_input) {
	std::string input = _input, temp;
	replaceWs(input); // replace all whitespace for just a space

	std::stringstream iss(input);
	while (std::getline(iss, temp, ' ')) {
		if (isAlphaString(input))
			throw BadInput();
		else if (isdigit(temp[0])) {
			double value = std::strtod(temp.c_str(), NULL);
			if (temp.size() == 1 && input.length() != temp.length())
				this->numbers.push(value);
			else
				throw BadInput();
		} else if (isOperator(temp[0])) {
			double a, b;
			if (this->numbers.size() < 2 && input.length() != temp.length())
				throw BadInput();
			a = this->numbers.top();
			this->numbers.pop();
			b = this->numbers.top();
			this->numbers.pop();
			double result = doTheMath(temp, a, b);
			this->numbers.push(result);
		}
		input.erase(0, temp.length() + 1);
	}

	if (this->numbers.size() == 1)
		std::cout << "The result of the operation is: " << this->numbers.top() << std::endl;
	else
	{
		std::cout << "fuck" << std::endl;


		throw BadInput();
	}
}

const char	*RPN::BadInput::what() const throw() {
	return "Error: Invalid input!\nInput: ";
}