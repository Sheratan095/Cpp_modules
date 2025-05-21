#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <algorithm> // for sort, lower_bound

// Constructors & Destructor
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

std::vector<size_t>	generateJacobsthalSequence(size_t n)
{
	std::vector<size_t>	sequence;
	size_t	j1 = 1;
	size_t	j2 = 1;

	while (j2 < n)
	{
		sequence.push_back(j2);
		size_t temp = j2;
		j2 = j2 + 2 * j1;
		j1 = temp;
	}

	std::reverse(sequence.begin(), sequence.end()); // Insert from large to small
	return sequence;
}

void	insertWithBinarySearch(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator	pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

std::vector<int>	PmergeMe::sortVector(const std::vector<int>& input)
{
	if (input.size() <= 1)
		return	(input);

	// Step 1: Create pairs of (min, max)
	std::vector<std::pair<int, int>>	pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	// Handle odd element if exists
	bool hasOdd = (input.size() % 2 != 0);
	int oddElement = hasOdd ? input[input.size() - 1] : 0;

	// Step 2: Recurse on the second (larger) elements
	std::vector<int> secondElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		secondElements.push_back(pairs[i].second);

	std::vector<int> mainChain = sortVector(secondElements);

	// Step 3: Insert smaller elements
	std::vector<int> pendingElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		pendingElements.push_back(pairs[i].first);

	// Insert first manually
	std::vector<bool> inserted(pendingElements.size(), false);
	insertWithBinarySearch(mainChain, pendingElements[0]);
	inserted[0] = true;

	// Step 4: Jacobsthal sequence insertion
	std::vector<size_t> jacobSeq = generateJacobsthalSequence(pendingElements.size());

	for (size_t i = 0; i < jacobSeq.size(); ++i)
	{
		size_t idx = jacobSeq[i];
		if (idx < pendingElements.size() && !inserted[idx])
		{
			insertWithBinarySearch(mainChain, pendingElements[idx]);
			inserted[idx] = true;
		}
	}

	// Insert remaining pending values
	for (size_t i = 1; i < pendingElements.size(); ++i)
	{
		if (!inserted[i])
		{
			insertWithBinarySearch(mainChain, pendingElements[i]);
			inserted[i] = true;
		}
	}

	// Step 5: Insert odd element
	if (hasOdd)
		insertWithBinarySearch(mainChain, oddElement);

	return (mainChain);
}
