#include "Date.hpp"
#include <iostream>

int main()
{
	try
	{
		Date date1("2023-10-00");
		Date date2("2023-10-05");
		Date date3("2023-10-06");

		std::cout << date1.toString() << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}