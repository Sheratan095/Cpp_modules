#include <iostream>
#include <fstream>

void			replace(std::ifstream file, std::string s1, std::string s2);

// std::ios::in file opening in reading mode
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl
				<< "\tThe rigth format is <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	fileName = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream inputFile;
	inputFile.open(fileName.c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: file '"
				<< fileName
				<< "' can't not be opened" << std::endl;
		return (1);
	}


	fileName.append(".replace");

	std::ofstream outputFile;
	outputFile.open(fileName.c_str(), std::ios::in | std::ios::trunc);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: file '"
				<< fileName
				<< "' can't not be opened" << std::endl;
		return (1);
	}
}

void	replace(std::ifstream file, std::ifstream outfile, std::string s1, std::string s2)
{

}	
