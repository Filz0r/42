#include "BitcoinExchange.hpp"

const char *CannotOpenFile::what() const throw () {
	return "Error: Cannot open file!";
}

const char *InvalidFile::what() const throw () {
	return "Error: File contents aren't valid!";
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
		case 4: case 6: case 9: case 11:
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
	if (this->year != obj.year || this->month != obj.month || this->day != obj.day)
		return false;
	return true;
}

bool DateObj::operator<(const DateObj &obj) const {
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
		BitcoinExchange::mapInit(BitcoinExchange::originalDbFile, ',', this->db);
		BitcoinExchange::mapInit(this->dbFile, '|', this->inputDb);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { (void)obj; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj) { (void)obj; return *this; }

bool	BitcoinExchange::isHeaderCorrect(const std::string &head,
										 BitcoinExchange::Type t) {
	std::stringstream ss(head);
	std::string dateStr, valueStr, extraColumns;

	std::getline(ss, dateStr, t == DB ? ',' : '|');
	std::getline(ss, valueStr, t == DB ? ',' : '|');

	std::string::iterator it;
	for (it = dateStr.begin(); it != dateStr.end() && std::isspace(*it); ++it) ;
	dateStr.erase(dateStr.begin(), it);
	for (it = dateStr.end(); it != dateStr.begin() && std::isspace(*(it -1)); --it) ;
	dateStr.erase(it, dateStr.end());
	for (it = valueStr.begin(); it != valueStr.end() && std::isspace(*it); ++it) ;
	valueStr.erase(valueStr.begin(), it);
	for (it = valueStr.end(); it != valueStr.begin() && std::isspace(*(it - 1)); --it) ;
	valueStr.erase(it, valueStr.end());

	if (dateStr.empty() || valueStr.empty() || dateStr != "date"
		|| ((t == INPUT  && valueStr != "value") || (t == DB  && valueStr != "exchange_rate"))
		|| ss >> extraColumns) {
			return false;
	}
	return true;
}

void	BitcoinExchange::mapInit(const std::string &filePath, const char delimiter,
								 std::multimap<keyStr, double> &toSet) {
	std::ifstream	database(filePath.c_str());
	std::string		line, date;
	double			value;

	if (!database.is_open())
		throw CannotOpenFile();

	// Parsing first line
	std::getline(database, line);
	Type temp = delimiter == '|' ? INPUT : DB;
	if (!BitcoinExchange::isHeaderCorrect(line, temp))
		throw InvalidFile();

	int i = 0;
	while (std::getline(database, line)) {
		std::string valueStr, extraInput, extraColumns;

		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::getline(ss, date, delimiter);

		ss >> valueStr;
		std::stringstream valueSs(valueStr);

		if (!(valueSs >> value) || valueSs >> extraInput || ss >> extraColumns)
			value = std::numeric_limits<double>::infinity();

		std::string::iterator it;
		// while we only have whitespace at the start increment it;
		for (it = date.begin(); it != date.end() && std::isspace(*it); ++it) ;
		// delete everything from begin up to it;
		date.erase(date.begin(), it);
		// while we only have whitespace at the end decrement it;
		for (it = date.end(); it != date.begin() && std::isspace(*(it - 1)); --it) ;
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
//	 Check if line is empty or we reached the eof and the db is still empty
	if ((database.eof() && toSet.empty()))
		throw InvalidFile();
}

std::pair<BitcoinExchange::keyStr, double>	BitcoinExchange::getClosestDate(const DateObj &toFind) {
	std::map<keyStr, double>::const_iterator it = this->db.begin();
	std::map<keyStr, double>::const_iterator closest = it;
	DateObj closestObj(it->first.second);

	for (; it != this->db.end(); ++it)
	{
		DateObj temp(it->first.second);
		if (temp == toFind)
			return *it;

		// Calculate the difference in days between the current date and the input date
		int currentDifference = closestDifference(temp, toFind);

		// Calculate the difference in days between the closest date and the input date
		int closestDiff = closestDifference(closestObj, toFind);

		if (currentDifference < closestDiff){
			closest = it;
			closestObj = DateObj(closest->first.second);
		}
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
				std::pair<keyStr, double> temp2 = this->getClosestDate(temp);
				std::cout << it->first.second << " => " << it->second << " = " << it->second * temp2.second << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << it->first.second << std::endl;
		}
	}
}