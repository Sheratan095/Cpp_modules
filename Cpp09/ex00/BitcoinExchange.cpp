#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filePath)
{
	std::ifstream	file(filePath.c_str());
	std::string		line;

	if (!file.is_open())
		throw (InvalidFileException());

	// file format is YYYY-MM-DD,value_int.value_decimal
	for (int i = 1; getline(file, line); ++i)
	{
		// check the format of first line
		if (i == 1)
		{
			if (line != "date,exchange_rate")
				throw (InvalidFileException());
		}

		if (line.length() < 12)
			throw (InvalidFileException());

		if (line[11] != ',')
			throw (InvalidFileException());

		std::string	dateStr = line.substr(0, 10);

		// get the value of the exchange rate
		std::string	valueStr = line.substr(11);
		char	*end;
		float	value = std::strtof(valueStr.c_str(), &end);
		if (*end != '\0' || value < 0)
			throw (InvalidFileException());

		try
		{
			Date	date(dateStr);
			this->_values[date] = value;
		}
		catch (const Date::InvalidDateException &e)
		{
			throw (InvalidFileException());
		}
	}

	file.close();
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _values(copy._values)
{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_values = rhs._values;

	return (*this);
}

const char*	BitcoinExchange::InvalidFileException::what() const throw()
{
	return ("The file is invalid");
}
