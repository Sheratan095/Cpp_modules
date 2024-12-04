#include "Harl.hpp"
#include <string.h>

int main (int argc, char *argv[])
{
	Harl		harl;
	std::string	input;


	if (argc != 2 || strlen(argv[1]) == 0)
	{
		std::cout << "Error invalid input" << std::endl;
		return (1);
	}

	input = argv[1];
	harl.complain(input);
}