#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float> _values;

	public:
		BitcoinExchange(const std::string	&filePath);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		BitcoinExchange&	operator=(const BitcoinExchange &rhs);

		class InvalidFileException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

#endif