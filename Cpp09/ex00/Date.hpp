#ifndef DATE_HPP
#define DATE_HPP

#include <string>

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

		Date	&operator=(const Date &rhs);
};

#endif