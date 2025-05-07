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

		void	parseInputFile(const std::string &input) const;

		BitcoinExchange&	operator=(const BitcoinExchange &rhs);

		class InvalidFileException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class EmptyDatabaseException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

#endif