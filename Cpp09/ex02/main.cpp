#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip> // for std::setprecision
#include <cstdlib> // for atol
#include <cctype> // for isdigit
#include <string> // for string operations
#include <climits> // for INT_MAX
#include "PmergeMe.hpp"

// Function to check if a string contains only digits
bool	convertNumber(const char* str, int& result);
void	printArray(const std::vector<int>& arr);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided." << std::endl;
		return (1);
	}

	PmergeMe			sorter;
	std::vector<int>	vecInput;
	std::list<int>		listInput;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			int	number;

			if (!convertNumber(argv[i], number))
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}

			vecInput.push_back(number);
			listInput.push_back(number);
		}
	}
	catch (std::exception& ex)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	// Check for empty input
	if (vecInput.empty())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	// Display unsorted input
	std::cout << "Before:";
	printArray(vecInput);

	// Time vector sort
	clock_t	start_vector = clock();
	std::vector<int>	vecSorted = sorter.sortVector(vecInput);
	clock_t	end_vector = clock();
	double	time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

	// Time list sort
	clock_t	start_list = clock();
	std::list<int>	listSorted = sorter.sortList(listInput);
	clock_t	end_list = clock();
	double	time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

	// Display sorted output
	std::cout << "After:";
	for (size_t i = 0; i < vecSorted.size(); ++i)
		std::cout << " " << vecSorted[i];
	std::cout << std::endl;

	// Display timing results
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vecInput.size() << " elements with std::vector : " 
			  << time_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << listInput.size() << " elements with std::list : " 
			  << time_list << " us" << std::endl;

	return (0);
}

bool	convertNumber(const char* str, int& result)
{
	if (!str || str[0] == '\0')
		return (false);

	size_t i = 0;
	if (str[0] == '+') 
		i = 1;

	for (; str[i] != '\0'; ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}

	long value = std::atol(str);
	if (value < 0 || value > INT_MAX)
		return (false);

	result = static_cast<int>(value);

	return (true);
}

void	printArray(const std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}