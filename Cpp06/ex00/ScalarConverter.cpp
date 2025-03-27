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

//----------------------------------------------------------------------------------------------

int	getPrecision(const std::string& rawValue)
{
	// Default precision is 0
	//	if precision is 1: 42 => 42.0, with 0 precision: 42 => 42
	int		precision = 0;

	// Find the position of the decimal point
	size_t	dotPosition = rawValue.find('.');

	// if the decimal point is found, calculate the precision
	if (dotPosition != std::string::npos)
	{
		// Retrieve the number of digits after the decimal point
		//	len - deciamal part - 1 (for the dot)
		precision = static_cast<int>(rawValue.length() - dotPosition - 1);

		// If the string ends with f
		//		=> remove 1 from the precision
		precision -= static_cast<int>(rawValue.find('f') != std::string::npos ? 1 : 0);
	}

	return (precision);
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

int	findOccurrences(const std::string &str, char c)
{
	int	count = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == c)
			count++;
	}

	return (count);
}

bool	isStringValid(const std::string &rawValue)
{
	//Check the string is empty or contains only spaces
	if (rawValue.empty() || strContainsJust(rawValue, " "))
	{
		std::cerr << "Error: empty string" << std::endl;
		return (false);
	}

	if (rawValue.size() == 1 && !isdigit(rawValue[0]))
		return (true);

	//Check the string contains the 'special' characters only once
	if (findOccurrences(rawValue, '.') > 1 || findOccurrences(rawValue, 'f') > 1
		|| findOccurrences(rawValue, '-') > 1 || findOccurrences(rawValue, '+') > 1)
	{
		std::cerr << "Error: invalid string" << std::endl;
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
int	getType(const std::string &rawValue)
{
	int	i = 0;
	int	type = -1;

	if (rawValue.size() == 1 && !isdigit(rawValue[0]))
		return (1);

	// skip sign
	while (rawValue[i] == '-' || rawValue[i] == '+')
		i++;
	// skip digits
	while (rawValue[i] >= '0' && rawValue[i] <= '9')
		i++;

	// if contains a dot
	//	=> it's a double or a float
	if (rawValue[i] == '.')
	{
		// set type to double beacasue the float is checked later
		type = 3;

		// skip dot
		i++;

		// skip digits again to skip the decimal part
		while (rawValue[i] >= '0' && rawValue[i] <= '9')
			i++;
	}

	// if the last char is f
	//		=> it's a float
	// else if the type is not double and the length is less than 13 (max len of int)
	//		=> it's an int
	if (rawValue[i] == 'f')
		type = 2;
	else if (type != 3 && rawValue.size() < 13)
		type = 4;

	return (type);
}

bool	checkForPseudoliteral(const std::string &rawValue)
{
	if (rawValue == "nan" || rawValue == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}

	if (rawValue == "+inf" || rawValue == "-inf" || rawValue == "+inff" || rawValue == "-inff")
	{
		const bool isInfiniteFloat = rawValue == "+inff" || rawValue == "-inff";

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (isInfiniteFloat ? rawValue : rawValue + "f") << std::endl;
		std::cout << "double: " << (isInfiniteFloat ? rawValue.substr(0, 4) : rawValue) << std::endl;
		return (true);
	}

	return (false);
}

void	convertChar(const std::string &str)
{
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertFloat(const std::string &str)
{
	// Cast to float
	float f = std::strtof(str.c_str(), NULL);

	// Check if the float is in the range of displayable characters
	if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// Check if the float is in the range of integers
	if (f <= static_cast<float>(INT_MAX) && f >= static_cast<float>(INT_MIN))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	// std::Fixed sets the floatfield format flag for the str stream to fixed.
	// 	When floatfield is set to fixed, floating-point values are written using fixed-point notation: 
	//		the value is represented with exactly as many digits in the decimal part as specified by the precision field (setprecision())
	std::cout << "float: " << std::fixed << std::setprecision(getPrecision(str)) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<double>(f) << std::endl;

}

void	convertDouble(const std::string &str)
{
	// Cast to float
	double d = std::strtod(str.c_str(), NULL);

	// Check if the float is in the range of displayable characters
	if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// Check if the int is in the range of integers
	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: "<< std::fixed << std::setprecision(getPrecision(str)) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << d << std::endl;
}

void	convertInt(const std::string &str)
{
	// Check if the number exeeds the range of int
	long l = std::atol(str.c_str());
	if (l < INT_MIN || l > INT_MAX)
	{
		std::cout << "Can't parse " << str << " as a int" << std::endl;
		return ;
	}

	int i = std::atoi(str.c_str());

	// Check if the float is in the range of displayable characters
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::convert(const std::string &rawValue)
{
	if (checkForPseudoliteral(rawValue))
		return ;

	if (!isStringValid(rawValue))
		return ;

	int	type = getType(rawValue);
	switch (type)
	{
		case 1: // CHAR
			convertChar(rawValue);
			break;
		case 2: // FLOAT
			convertDouble(rawValue);
			break;
		case 3: // DOUBLE
			convertFloat(rawValue);
			break;
		case 4: // INT
			convertInt(rawValue);
			break;

		// it works both for unknown(-1) and default
		case -1:
		default:
			std::cerr << "Error: invalid string" << std::endl;
			break;
	}
}
