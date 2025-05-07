#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float> _values;

	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

};

#endif