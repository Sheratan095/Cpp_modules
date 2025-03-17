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

bool	checkForSpeudoliteral(const std::string &rawValue);
void	printResult(const std::string &charVal, const std::string &intVal, const std::string &floatVal,
								const std::string &doubleVal);

void	ScalarConverter::convert(const std::string &rawValue)
{
	if (checkForSpeudoliteral(rawValue))
		return ;
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
