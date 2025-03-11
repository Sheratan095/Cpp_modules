#include "ScalarConverter.hpp"

#include <iostream>

int main(/*int argc, char **argv*/)
{
	// ScalarConverter sc;
	std::string	test = "nan";

	// if (argc != 2)
	// {
		// std::cout << "Usage: ./convert [value]" << std::endl;
		// return (1);
	// }

	ScalarConverter::convert(test);

	return (0);
}