#include "RPN.hpp"

Rpn::Rpn()
{}

Rpn::Rpn(const Rpn &source)
{
	// just for flag compilation
	(void)source;
}

Rpn::~Rpn()
{}

float	Rpn::parseInput(const std::string& input) const
{
	// 1, 2... (numbers)
	std::stack<float>	operands;

	std::stringstream	sstream(input);
	std::string			element;

	// literrally split the string by space
	while (sstream >> element)
	{
		std::cout << "Element: " << element << std::endl;
	}

	return (0);
}

float	doSingleCalc(float a, float b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw (std::runtime_error("Division by zero"));
			return (a / b);
		default:
			throw (std::runtime_error("Invalid operator"));
	}
}

Rpn &Rpn::operator=(const Rpn &rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}