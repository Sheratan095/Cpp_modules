
#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: usage: ./RPN [rpn expression]" << std::endl;
		return (1);
	}

	try
	{
		Rpn	rpn;
		// float result = rpn.parseInput(argv[1]);
		std::cout << "Result: " << argv[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
}