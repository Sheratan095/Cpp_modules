#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for sort, lower_bound

// Constructors & Destructor
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

void	insertWithBinarySearch(std::vector<int>& vec, int element)
{
	// Find the position to insert the element using binary search
	// and insert it in sorted order
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), element);
	vec.insert(it, element);
}

std::vector<int>	PmergeMe::sortVector(const std::vector<int>& input)
{
	// Handle base cases
	if (input.size() <= 1)
		return (input);

	int		odd_element = -1;
	bool	has_odd = (input.size() % 2 != 0);
	
	// Step 1: Create pairs
	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < input.size() - (has_odd ? 1 : 0); i += 2) {
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}
	
	// Save the odd element if exists
	if (has_odd)
		odd_element = input[input.size() - 1];
	
	// Step 2: Extract larger elements
	std::vector<int>	larger_elements;
	for (size_t i = 0; i < pairs.size(); i++)
		larger_elements.push_back(pairs[i].first);
	
	// Step 3: Recursively sort larger elements
	larger_elements = sortVector(larger_elements);
	
	// Step 4: Create result array with sorted larger elements
	std::vector<int>	result = larger_elements;
	
	// Step 5: Insert smaller elements using binary insertion
	for (size_t i = 0; i < pairs.size(); i++)
		insertWithBinarySearch(result, pairs[i].second);
	
	// Step 6: Insert the odd element if exists
	if (has_odd)
		insertWithBinarySearch(result, odd_element);
	
	return (result);
}

//------------------------------------------------------------------------------------

std::list<int>	PmergeMe::sortList(const std::list<int>& input)
{
	// Handle base cases
	if (input.size() <= 1)
		return input;

	int		odd_element = -1;
	bool	has_odd = (input.size() % 2 != 0);
	
	// Step 1: Create pairs
	std::vector<std::pair<int, int> >	pairs;
	std::list<int>::const_iterator		it = input.begin();
	while (it != input.end())
	{
		int	first = *it++;
		if (it == input.end()) {
			odd_element = first;
			break;
		}

		int	second = *it++;
		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	
	// Step 2: Extract larger elements
	std::list<int>	larger_elements;
	for (size_t i = 0; i < pairs.size(); i++)
		larger_elements.push_back(pairs[i].first);
	
	// Step 3: Recursively sort larger elements
	larger_elements = sortList(larger_elements);
	
	// Step 4: Create result list with sorted larger elements
	std::list<int>	result = larger_elements;
	
	// Step 5: Insert smaller elements using binary insertion
	for (size_t i = 0; i < pairs.size(); i++)
	{
		int element_to_insert = pairs[i].second;
		
		// Find insertion position
		std::list<int>::iterator insert_position = result.begin();
		std::advance(insert_position, std::min(i + 1, result.size()));
		
		std::list<int>::iterator search_it = result.begin();
		for (size_t j = 0; j <= i; j++)
		{
			if (*search_it >= element_to_insert)
				break;
			if (j < i)
				++search_it;
		}
		
		result.insert(search_it, element_to_insert);
	}
	
	// Step 6: Insert the odd element if exists
	if (has_odd)
	{
		std::list<int>::iterator position = result.begin();
		while (position != result.end() && *position < odd_element)
			++position;
		result.insert(position, odd_element);
	}
	
	return result;
}
