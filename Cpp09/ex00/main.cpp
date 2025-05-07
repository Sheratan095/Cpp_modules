#include "Date.hpp"
#include <iostream>

int main()
{
	try
	{
		Date date1("2023-10-0asa");
		Date date2("2023-10-05");
		Date date3("2023-10-06");

		if (date1 == date2)
			std::cout << "Date 1 is equal to Date 2" << std::endl;
		else
			std::cout << "Date 1 is not equal to Date 2" << std::endl;

		if (date1 == date3)
			std::cout << "Date 1 is equal to Date 3" << std::endl;
		else
			std::cout << "Date 1 is not equal to Date 3" << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}