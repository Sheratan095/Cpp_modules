#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}

void	printResult(const std::string &charVal, const std::string &intVal, const std::string &floatVal,
								const std::string &doubleVal)
{
	std::cout << "char" << ": " << charVal << std::endl;
	std::cout << "int" << ": " << intVal << std::endl;
	std::cout << "float" << ": " << floatVal << std::endl;
	std::cout << "double" << ": " << doubleVal << std::endl;
}

bool	checkForSpeudoliteral(const std::string &rawValue)
{
	if (rawValue == "nan" || rawValue == "nanf")
	{
		printResult("impossible", "impossible", "nanf", "nan");
		return (true);
	}

	if (rawValue == "+inf" || rawValue == "-inf" || rawValue == "+inff" || rawValue == "-inff")
	{
		const bool isInfiniteFloat = rawValue == "+inff" || rawValue == "-inff";

		printResult(
			"impossible",
			"impossible",
							//? +/-inff : +/-inff
			isInfiniteFloat ? rawValue : rawValue + "f", //Used to add f if needed
							//? +/-inf : +/-inf
			isInfiniteFloat ? rawValue.substr(0, 4) : rawValue //Used to remove f if needed
		);
		return (true);
	}

	return (false);
}

bool	strContainsJust(const std::string &str, const std::string &allowedChars)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (allowedChars.find(str[i]) == std::string::npos)
			return (false);
	}
	return (true);
}

bool	isStringValid(const std::string &rawValue)
{
	//Check the string is empty or contains only spaces
	if (rawValue.empty() || strContainsJust(rawValue, " "))
	{
		std::cerr << "Error: empty string" << std::endl;
		return (false);
	}

	//Check the string contains only valid characters
	if (strContainsJust(rawValue, "0123456789.-+f") == false)
	{
		std::cerr << "Error: invalid string" << std::endl;
		return (false);
	}

	//Check the string contains more than one char
	bool	charFound = false;
	for (size_t i = 0; i < rawValue.size(); i++)
	{
		if (isalpha(rawValue[i] ))
		{
			if (charFound)
			{
				std::cerr << "Error: invalid string" << std::endl;
				return (false);
			}
			charFound = true;
		}
	}

	return (true);
}

/*
	CHAR:	1
	FLOAT:	2
	DOUBLE:	3
	INT:	4
	UNKNOWN	-1
*/
int	getType(const std::string &rawvalue)
{
	int	i = 0;
	int	type = -1;

	if (rawvalue.size() == 1 && isalpha(rawvalue[0]))
		return (1);

	// skip sign
	while (rawvalue[i] == '-' || rawvalue[i] == '+')
		i++;
	// skip digits
	while (rawvalue[i] >= '0' && rawvalue[i] <= '9')
		i++;

	// if contains a dot
	//	=> it's a double or a float
	if (rawvalue[i] == '.')
	{
		// set type to double beacasue the float is checked later
		type = 3;

		// skip dot
		i++;

		// skip digits again to skip the decimal part
		while (rawvalue[i] >= '0' && rawvalue[i] <= '9')
			i++;
	}

	// if the last char is f
	//		=> it's a float
	// else if the type is not double and the length is less than 13 (max len of int)
	//		=> it's an int
	if (rawvalue[i] == 'f')
		type = 2;
	else if (type != 3 && rawvalue.size() < 13)
		type = 4;

	return (type);
}

void	convertChar(const std::string &str)
{
	char	c = str[0];
	int		i = static_cast<int>(c);

	printResult(c, i, static_cast<float>(c) , static_cast<double>(c));
}


void	ScalarConverter::convert(const std::string &rawValue)
{
	if (!isStringValid(rawValue))
		return ;

	if (checkForSpeudoliteral(rawValue))
		return ;

	int	type = getType(rawValue);
	switch (type)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;

		// it works both for unknown(-1) and default
		case -1:
		default:
			std::cerr << "Error: invalid string" << std::endl;
			break;
	}
}
