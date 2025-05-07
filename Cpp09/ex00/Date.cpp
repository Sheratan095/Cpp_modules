#include "Date.hpp"

Date::Date(const std::string &dateString)
{
	std::string::values[] = dateString.sli
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

bool	Date::operator==(const Date &rhs) const
{
	return (this->_year == rhs._year && this->_month == rhs._month && this->_day == rhs._day);
}

const char*	Date::InvalidDateException::what() const throw()
{
	return ("Invalid date");
}
