#include <iostream>

/* References:
 Acts as an alias to string.
 Any operation on the references directly affects string.
 Cannot be reassigned to refer to another string.
*/

int main()
{
	std::string	string	= "HI THIS IS BRAIN";

	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::endl;

	std::cout << "Address of string is:\t" << &string << std::endl;
	std::cout << "stringPTR is:\t\t" << stringPTR << std::endl;
	std::cout << "stringREF is:\t\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string is:\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t" << stringREF << std::endl;
}