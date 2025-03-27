#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	public:
		static void	convert(const std::string &rawValue);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);

		// Used to make the class abstract
		virtual	~ScalarConverter() = 0;

		ScalarConverter	&operator=(const ScalarConverter &rhs);
};

#endif