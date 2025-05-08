#include "Date.hpp"

Date::Date()
{}

// Rigth format is YYYY-MM-DD
Date::Date(const std::string &dateString)
{
	if (dateString.length() != 10 || dateString[4] != '-' || dateString[7] != '-')
		throw (InvalidDateException());

	std::string	str_year = dateString.substr(0, 4);
	std::string	str_month = dateString.substr(5, 2);
	std::string	str_day = dateString.substr(8, 2);

	if (str_year.length() != 4 || str_month.length() != 2 || str_day.length() != 2)
		throw (InvalidDateException());

	// strtol(): convert c string to long
	// 	endptr point to the first char after the number, if it's not \0, the string doesn't contains only digits
	// 	10: indicate the base of the number system (decimal)
	char	*endptr;

	_year = std::strtol(str_year.c_str(), &endptr, 10);
	if (*endptr != '\0')
		throw (InvalidDateException());
	_month = std::strtol(str_month.c_str(), &endptr, 10);
	if (*endptr != '\0')
		throw (InvalidDateException());
	_day = std::strtol(str_day.c_str(), &endptr, 10);
	if (*endptr != '\0')
		throw (InvalidDateException());

	if (_year < 0 || _month < 1 || _month > 12 || _day < 1 || _day > 31)
		throw (InvalidDateException());

	// February
	if (_month == 2)
	{
		// anno bisestile
		//  se l'anno solare è divisibile per 4
		//  tuttavia, se è anche divisibile per 100 allora, è un anno normale
		//  a meno che l'anno solare non sia divisibile per 400, allora è di nuovo bisestile
		bool	isLeapYear = (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0));

		// se è bisestile: ha 29 giorni, altrimenti 28
		if (_day > (isLeapYear ? 29 : 28))
			throw (InvalidDateException());
	}

	//	April,			June,		   September,	  November		have 30 days
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		if (_day > 30)
			throw (InvalidDateException());
	}
}

Date::Date(const Date &source):
	_year(source._year),
	_month(source._month),
	_day(source._day)
{}

Date::~Date()
{}

Date&	Date::operator=(const Date &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_year = rhs._year;
	this->_month = rhs._month;
	this->_day = rhs._day;

	return (*this);
}

std::string	Date::toString() const
{
	std::stringstream ss;

	ss << this->_year;
	ss << "-";
	if (this->_month < 10)
		ss << "0";
	ss << this->_month;
	ss << "-";
	if (this->_day < 10)
		ss << "0";
	ss << this->_day;

	return (ss.str());
}

bool	Date::operator==(const Date &rhs) const
{
	return (this->_year == rhs._year && this->_month == rhs._month && this->_day == rhs._day);
}

bool	Date::operator<(const Date &rhs) const
{
	if (this->_year != rhs._year)
		return (this->_year < rhs._year);
	if (this->_month != rhs._month)
		return (this->_month < rhs._month);
	return (this->_day < rhs._day);
}

bool	Date::operator>(const Date &rhs) const
{
	if (this->_year != rhs._year)
		return (this->_year > rhs._year);
	if (this->_month != rhs._month)
		return (this->_month > rhs._month);
	return (this->_day > rhs._day);
}

const char*	Date::InvalidDateException::what() const throw()
{
	return ("Invalid date");
}
