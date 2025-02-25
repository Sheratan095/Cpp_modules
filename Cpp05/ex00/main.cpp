#include "Bureaucrat.hpp"

int main()
{
	// try
	// {
		Bureaucrat bob("Bob", 200);
		std::cout << bob << std::endl;
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << alice << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}