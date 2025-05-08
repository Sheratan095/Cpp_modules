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

// tryParse: convert a string to a float
float	Rpn::tryParse(const std::string& str) const
{
	char	*end;
	float	value = std::strtof(str.c_str(), &end);

	if (*end != '\0')
		throw (InvalidRpnExpressionException());

	if (value < 0 || value > 9)
		throw (NumberOutOfRangeException());

	return (value);
}

float	Rpn::parseInput(const std::string& input) const
{
	if (input.empty())
		throw (InvalidRpnExpressionException());

	// 1, 2... (numbers)
	std::stack<float>	operands;

	std::stringstream	sstream(input);
	std::string			element;

	// literrally split the string by space
	while (sstream >> element)
	{
		// if the element isn't an opeartor
		if (!isOperator(element))
		{
			try
			{
				// try to parse the element as a float and push it to the stack
				float	value = tryParse(element);
				operands.push(value);

				continue;
			}
			catch (const std::exception &e)
			{
				throw (InvalidRpnExpressionException());
			}
		}

		// if the element is an operator
		if (operands.size() < 2)
			throw (InvalidRpnExpressionException());

		//stack is now [n2, n1, ....]
		// because the second element has been pushed first

		// get the second element and remove it from the stack
		float	b = operands.top();
		operands.pop();

		// get the first element and remove it from the stack
		float	a = operands.top();
		operands.pop();

		float	result = doSingleCalc(a, b, element[0]);

		// push the result back to the stack
		operands.push(result);
	}

	// if there is more than one element in the stack, the expression is invalid
	//	means ther're too few operators
	if (operands.size() != 1)
		throw (InvalidRpnExpressionException());

	// return the remaining element in the stack
	return (operands.top());
}

float	Rpn::doSingleCalc(float a, float b, char operation) const
{
	switch (operation)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
	}
	throw (InvalidRpnExpressionException());
}

bool	Rpn::isOperator(const std::string& str) const
{
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (true);

	return (false);
}

Rpn &Rpn::operator=(const Rpn &rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}

const char *Rpn::InvalidRpnExpressionException::what() const throw()
{
	return ("Invalid expression");
}

const char *Rpn::NumberOutOfRangeException::what() const throw()
{
	return ("Number out of range");
}
