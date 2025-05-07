#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Date
{
	private:
		int	_year;
		int	_month;
		int	_day;

	public:
		Date(const std::string &dateString);
		Date(const Date &source);
		~Date();

		std::string	toString();

		Date&	operator=(const Date &rhs);
		bool	operator==(const Date &rhs) const;
		bool	operator<(const Date &rhs) const;
		bool	operator>(const Date &rhs) const;

		class InvalidDateException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif