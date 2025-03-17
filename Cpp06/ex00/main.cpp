#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	float c = 42.1f;

	std::cout << c << std::endl;

	ScalarConverter::convert(argv[1]);

	return (0);
}