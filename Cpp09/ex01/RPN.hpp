#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>

class Rpn
{
	public:
		Rpn();
		Rpn(const Rpn &src);
		~Rpn();

		float	parseInput(const std::string& input) const;

		Rpn &operator=(const Rpn &rhs);

};

#endif