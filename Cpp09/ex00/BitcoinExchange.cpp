#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filePath)
{
	std::ifstream	file(filePath.c_str());
	std::string		line;

	if (!file.is_open() || file.fail())
		throw (InvalidFileException());

	// file format is YYYY-MM-DD,value_int.value_decimal
	for (int i = 1; getline(file, line); ++i)
	{
		// check the format of first line
		if (i == 1)
		{
			if (line != "date,exchange_rate")
				throw (InvalidFileException());
			else
				continue;
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

void	BitcoinExchange::parseInputFile(const std::string& input) const
{
	std::ifstream	file(input.c_str());
	std::string		line;

	if (!file.is_open() || file.fail())
		throw (InvalidFileException());

	if (_values.empty())
		throw (EmptyDatabaseException());

	// file format is YYYY-MM-DD | value_int.value_decimal
	for (int i = 1; getline(file, line); ++i)
	{
		// check the format of first line
		if (i == 1 && line != "date | value")
		{
			std::cout << "Error: invalid file header" << line << std::endl;
			return;
		}

		if (line.length() < 14 || line[12] != '|' || line[11] != ' ' || line[13] != ' ')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	dateStr;
		try
		{
			std::string	dateStr = line.substr(0, 10);
			Date	targetDate(dateStr);
		}
		catch (const std::exception &ex)
		{
			std::cout << "Error: bad date => " << dateStr << std::endl;
			continue;
		}

		// get the value of the exchange rate
		std::string	valueStr = line.substr(13);
		char	*end;
		long	value = std::strtof(valueStr.c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Error: value not a number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << value << std::endl;
			continue;
		}

		
	}

	file.close();
}

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

const char*	BitcoinExchange::EmptyDatabaseException::what() const throw()
{
	return ("The database is empty");
}
