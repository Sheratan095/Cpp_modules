#include "Date.hpp"

Date::Date(const std::string &dateString)
{
	// Parse the date string and initialize _year, _month, and _day
	// Example: "2023-10-05" -> _year = 2023, _month = 10, _day = 5
	// Implement parsing logic here
}

Date::Date(const Date &source) : 
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