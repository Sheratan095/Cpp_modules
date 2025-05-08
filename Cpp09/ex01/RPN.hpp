#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>


class Rpn
{
	private:
		float	tryParse(const std::string& str) const;
		float	doSingleCalc(float a, float b, char operation) const;
		float	isOperator(const std::string& str) const;


	public:
		Rpn();
		Rpn(const Rpn &src);
		~Rpn();

		float	parseInput(const std::string& input) const;

		Rpn &operator=(const Rpn &rhs);

		class InvalidRPNExpressionException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NumberOutOfRangeException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif