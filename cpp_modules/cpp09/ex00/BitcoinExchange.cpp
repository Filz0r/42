#include "BitcoinExchange.hpp"

const char *CannotOpenFile::what() const throw () {
	return "Error: Cannot open file!";
}

const char *InvalidDate::what() const throw () {
	return "Error: Date is not in the format <Year>-<Month>-<Day>!";
}

const char *InvalidValue::what() const throw () {
	return "Error: Value is not an int/float between 0 and 1000!";
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
	return os << "Day: " << obj.day << std::endl << "Month: "
		<< obj.month << std::endl << "Year: " << obj.year << std::endl
		<< "Is valid: " << (obj.isValid() ? "true" : "false") << std::endl;
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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	(void)obj;
	return *this;
}

void	BitcoinExchange::mapInit(const std::string &filePath, const char delimiter,
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

		std::getline(ss, date, delimiter);
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
		keyPair tempPair = keyPair(i, date);
		toSet.insert(std::pair<keyPair, double>(tempPair, value));

		// Trick to validate invalid inputs ;)
		date.clear();
		value = std::numeric_limits<double>::infinity();
		i++;
	}
}

void	BitcoinExchange::validateInput(std::multimap<keyPair, double> &db,
									   DateObj &date, double value) {
	if (value == std::numeric_limits<double>::infinity() || (value < 0 && value > 1000))
		throw InvalidValue();
	std::multimap<keyPair, double>::const_iterator it = db.begin();
	for (; it != db.end(); ++it)
	{
		DateObj temp(it->first.second);
		if (temp <= date)
		{
			std::cout << "lol" << std::endl;
			std::cout << "temp: " << temp << std::endl;
		}
	}
}

void	BitcoinExchange::printDb() {
	std::map<keyPair , double>::const_iterator it = db.begin();
	for (; it != db.end(); ++it) {
		std::cout << "db[" << it->first.second << "]: " << it->second << std::endl;
	}
}

void	BitcoinExchange::printInputDb() {
	std::map<keyPair, double>::const_iterator it = this->inputDb.begin();
	for (; it != this->inputDb.end(); ++it) {
			std::cout << "index: " << it->first.first <<" db[" << it->first.second << "]: " << it->second << std::endl;
	}
}

void	BitcoinExchange::run() {
//	this->printDb();
//	this->printInputDb();
	try {
		std::map<keyPair, double>::const_iterator it = this->inputDb.begin();
		for (; it != this->inputDb.end(); ++it) {
			DateObj temp(it->first.second);
			BitcoinExchange::validateInput(this->db, temp, it->second);
//		std::cout << it->first.second << " isValid: "
//			<< (temp.isValid() ? "true " : "false ") << "value: |"
//			<< it->second << "|"  << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}

