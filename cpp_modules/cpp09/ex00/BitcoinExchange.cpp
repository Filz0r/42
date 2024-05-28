#include <cstdlib>
#include "BitcoinExchange.hpp"

const char *CannotOpenFile::what() const throw () {
	return "Error: Cannot open file!";
}

const char *InvalidFile::what() const throw () {
	return "Error: File doesn't have anything inside!";
}

DateObj::DateObj(const std::string &date) {
	std::stringstream ss(date);
	char delimiter = '-';
	int _year, _month, _day;

	ss >> _year >> delimiter >> _month >> delimiter >> _day;

	this->year = _year;
	this->month = _month;
	this->day = _day;
}

DateObj::~DateObj() {}

bool	DateObj::isLeapYear() const {
	return (this->year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	DateObj::isValid() const {
	if (this->year < 2009 || this->month < 1 || this->month > 12)
		return false;

	int daysInMonth;
	switch (this->month) {
		case 2:
			daysInMonth = this->isLeapYear() ? 29 : 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		default:
			daysInMonth = 31;
			break;
	}

	if (day < 1 || day > daysInMonth)
		return false;
	// Checking if the day is before the start of the bitcoin network
	// https://en.wikipedia.org/wiki/History_of_bitcoin#Creation
	if (year == 2009 && month == 1 && day < 3)
		return false;
	return true;
}

bool DateObj::operator==(const DateObj &obj) const {
	if (this->year != obj.year
		|| this->month != obj.month
		|| this->day != obj.day)
		return false;
	return true;
}

bool DateObj::operator<(const DateObj &obj) const {
	// Copilot ftw pt2
	if (this->year < obj.year)
		return true;
	else if (this->year > obj.year)
		return false;

	// years are equal, compare months
	if (this->month < obj.month)
		return true;
	else if (this->month > obj.month)
		return false;

	// months are equal, compare days
	return this->day < obj.day;
}

bool DateObj::operator<=(const DateObj &obj) const {
	// CoPilot FTW
	if (this->year < obj.year)
		return true;
	else if (this->year > obj.year)
		return false;

	// years are equal, compare months
	if (this->month < obj.month)
		return true;
	else if (this->month > obj.month)
		return false;

	// months are equal, compare days
	return this->day <= obj.day;
}

std::ostream& operator <<(std::ostream &os, const DateObj &obj) {
	return os  << obj.year << "-" << obj.month << "-" << obj.day;
}

int	closestDifference(const DateObj &obj1, const DateObj &obj2) {
	return  abs((obj1.year * 365 + obj1.month * 30 + obj1.day) -
				(obj2.year * 365 + obj2.month * 30 + obj2.day));
}

const std::string BitcoinExchange::originalDbFile = "data.csv";

BitcoinExchange::BitcoinExchange(const std::string &_dbFile) : dbFile(_dbFile) {
	try {
		BitcoinExchange::mapInit(BitcoinExchange::originalDbFile, this->db);
		BitcoinExchange::mapInit(this->dbFile, this->inputDb);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { (void)obj; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj) {
	(void)obj;
	return *this;
}

void	BitcoinExchange::mapInit(const std::string &filePath,
								 std::multimap<keyPair, double> &toSet) {
	std::ifstream	database(filePath.c_str());
	std::string		line;
	std::string		date;
	double			value;

	if (!database.is_open())
		throw CannotOpenFile();

	// Ignore first line
	std::getline(database, line);
	int i = 0;
	while (std::getline(database, line)) {
		std::stringstream ss(line);

		std::getline(ss, date, ',');
		ss >> value;

		std::string::iterator it;
		// while we only have whitespace at the start increment it;
		for (it = date.begin(); it != date.end() && std::isspace(*it); ++it)
			;
		// delete everything from begin up to it;
		date.erase(date.begin(), it);
		// while we only have whitespace at the end decrement it;
		for (it = date.end(); it != date.begin() && std::isspace(*(it - 1)); --it)
			;
		// delete everything from it up until end
		date.erase(it, date.end());
		// Temporary pair so that we can order the list by insertion of elements
		keyPair tempPair = keyPair (i, DateObj(date));
		toSet.insert(std::pair<keyPair , double>(tempPair, value));

		// Trick to validate invalid inputs ;)
		date.clear();
		value = std::numeric_limits<double>::infinity();
		i++;
	}
}

void	BitcoinExchange::mapInit(const std::string &filePath,
								 std::multimap<keyStr, double> &toSet) {
	std::ifstream	database(filePath.c_str());
	std::string		line;
	std::string		date;
	double			value;

	if (!database.is_open())
		throw CannotOpenFile();

	// Ignore first line
	std::getline(database, line);
	// Check if file is empty
	if (line.empty())
		throw InvalidFile();

	int i = 0;
	while (std::getline(database, line)) {
		std::stringstream ss(line);
		std::string valueStr;

		std::getline(ss, date, '|');
		ss >> valueStr;

		std::stringstream valueSs(valueStr);
		std::string extraInput;
		std::string extraColumns;
		if (!(valueSs >> value) || valueSs >> extraInput || ss >> extraColumns)
			value = std::numeric_limits<double>::infinity();

		std::string::iterator it;
		// while we only have whitespace at the start increment it;
		for (it = date.begin(); it != date.end() && std::isspace(*it); ++it)
			;
		// delete everything from begin up to it;
		date.erase(date.begin(), it);
		// while we only have whitespace at the end decrement it;
		for (it = date.end(); it != date.begin() && std::isspace(*(it - 1)); --it)
			;
		// delete everything from it up until end
		date.erase(it, date.end());

		// Temporary pair so that we can order the list by insertion of elements
		keyStr tempPair = keyStr(i, date);
		toSet.insert(std::pair<keyStr , double>(tempPair, value));

		// Trick to validate invalid inputs ;)
		date.clear();
		value = std::numeric_limits<double>::infinity();
		i++;
	}
}

std::pair<BitcoinExchange::keyPair, double>	BitcoinExchange::getClosestDate(const DateObj &toFind) {
	std::map<keyPair, double>::const_iterator it = this->db.begin();
	std::map<keyPair, double>::const_iterator closest = it;
	for (; it != this->db.end(); ++it)
	{
		if (it->first.second == toFind)
			return *it;

		// Calculate the difference in days between the current date and the input date
		int currentDifference = closestDifference(it->first.second, toFind);

		// Calculate the difference in days between the closest date and the input date
		int closestDiff = closestDifference(closest->first.second, toFind);

		if (currentDifference < closestDiff)
			closest = it;
	}

	return *closest;
}

void	BitcoinExchange::run() {
	std::map<keyStr, double>::const_iterator it = this->inputDb.begin();
	for (; it != this->inputDb.end(); ++it) {
		DateObj temp = DateObj(it->first.second);
		double value = it->second;
		if (temp.isValid()) {
			if (value < 0) {
				std::cerr << "Error: not a positive number" << std::endl;
			} else if (value > 1000 && value != std::numeric_limits<double>::infinity()) {
				std::cerr << "Error: too large number" << std::endl;
			} else if (value == std::numeric_limits<double>::infinity()){
				std::cerr << "Error: invalid number/input" << std::endl;
			} else {
				std::pair<keyPair, double> temp2 = this->getClosestDate(temp);
				std::cout << it->first.second << " => " << it->second << " = " << it->second * temp2.second << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << it->first.second << std::endl;
		}
	}
}