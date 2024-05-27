#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <limits>

class CannotOpenFile : public std::exception {
	public:
		const char *what() const throw();
};

class InvalidDate : public std::exception {
public:
	const char *what() const throw();
};

class InvalidValue : public std::exception {
public:
	const char *what() const throw();
};

struct DateObj {
	public:
		int day;
		int month;
		int year;
		// Public Methods
		bool isLeapYear() const;
		bool isValid() const;

		// Constructor/destructor
		explicit DateObj(const std::string &date);
		~DateObj();

		// Operators
		bool	operator==(const DateObj &obj) const;
		bool	operator<=(const DateObj &obj) const;
};

std::ostream& operator <<(std::ostream &os, const DateObj &obj);

class BitcoinExchange
{
	typedef std::pair<int, std::string> keyPair;
	public:
		// default constructor
		explicit BitcoinExchange( const std::string &_dbFile );

		// Canonical stuff
      	~BitcoinExchange();

		// Public methods;
		void	run( void );
		void	printDb( void );
		void	printInputDb( void );

	private:
		// Canonical stuff
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &obj );
		BitcoinExchange& operator = ( const BitcoinExchange &obj );

		// Statatic vars/functions
		static const std::string	originalDbFile;
		static void	mapInit( const std::string &filePath, char delimiter,
								std::multimap<keyPair, double> &toSet );
		static void validateInput( std::multimap<keyPair, double> &db,
								   DateObj &date, double value);

		// Private methods

		// Class attributes
		std::string						dbFile;
  		std::multimap<keyPair , double>	db;
  		std::multimap<keyPair , double>	inputDb;
};