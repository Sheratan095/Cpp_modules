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

		if (line[10] != ',')
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
		if (i == 1)
		{ 
			if(line != "date | value")
			{
				std::cout << "Error: invalid input file" << std::endl;
				return;
			}
			else
				continue;
		}

		if (line.length() < 14 || line[11] != '|' || line[10] != ' ' || line[12] != ' ')
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	dateStr;
		Date	targetDate;
		try
		{
			dateStr = line.substr(0, 10);
			targetDate = Date(dateStr);
		}
		catch (const Date::InvalidDateException &ex)
		{
			std::cout << "Error: bad date => " << dateStr << std::endl;
			continue;
		}

		// get the value of the exchange rate
		std::string	valueStr = line.substr(13);
		char	*end;
		float	value = std::strtof(valueStr.c_str(), &end);
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
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		try
		{
			std::pair<Date, float> closestDate = getClosestLowerDate(targetDate);
			std::cout << closestDate.first.toString() << " => " << value << " = " << closestDate.second * value << std::endl;
		}
		catch(const EmptyDatabaseException& e)
		{
			std::cout << "Error: no data available for or before " << dateStr << std::endl;
		}
		
	}

	file.close();
}

std::pair<Date, float>	BitcoinExchange::getClosestLowerDate(const Date &date) const
{
	// First try to find an exact match for the date
	std::map<Date, float>::const_iterator it = this->_values.find(date);

	// If we found an exact date match, return that date and its value
	if (it != this->_values.end())
		return (std::make_pair(it->first, it->second));

	// If no exact match, use lower_bound to find the smallest key not less than the date
	// (lower_bound returns iterator pointing to the first element >= date)
	it = this->_values.lower_bound(date);

	// This check is necessary and should be uncommented!
	// If lower_bound returns the beginning of the map, it means all dates in the database
	// are greater than the requested date, so there's no "closest lower date"
	if (it == this->_values.begin())
		throw (EmptyDatabaseException());

	// Since lower_bound gives us the first element >= date,
	// we need to move back one step to get the closest date that's < date
	--it;
	return (std::make_pair(it->first, it->second));
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
