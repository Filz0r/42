#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <limits>
#include <cstdlib>

class CannotOpenFile : public std::exception {
	public:
		const char *what() const throw();
};

class InvalidFile : public std::exception {
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
		bool	operator<(const DateObj &obj) const;
};

std::ostream& operator <<(std::ostream &os, const DateObj &obj);

int closestDifference (const DateObj &obj1, const DateObj &obj2);

class BitcoinExchange
{

	public:
		// default constructor
		explicit BitcoinExchange( const std::string &_dbFile );

		// Canonical stuff
      	~BitcoinExchange();

		// Public methods;
		void	run( void );

	private:
		// Private types
		typedef std::pair<int, std::string> keyStr;
		enum Type {
			DB,
			INPUT
		};

		// Canonical stuff
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &obj );
		BitcoinExchange& operator = ( const BitcoinExchange &obj );

		// Statatic vars/functions
		static const std::string	originalDbFile;
		static void	mapInit( const std::string &filePath, const char delimiter,
								std::multimap<keyStr, double> &toSet );
		static bool isHeaderCorrect(const std::string &head, Type t);

		// Private methods
		std::pair<keyStr, double> 	getClosestDate(const DateObj &toFind);

		// Class attributes
		std::string						dbFile;
  		std::multimap<keyStr , double>	db;
  		std::multimap<keyStr , double>	inputDb;
};