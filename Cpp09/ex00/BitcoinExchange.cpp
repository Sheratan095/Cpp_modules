#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filePath)
{
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