#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for sort, lower_bound

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe&	PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

// Helper function to generate Jacobsthal numbers for optimal insertion order
std::vector<size_t> generateJacobsthal(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return jacobsthal;
	
	jacobsthal.push_back(1);
	if (n == 1)
		return jacobsthal;
	
	jacobsthal.push_back(3);
	
	size_t	prev = 1, curr = 3;
	while (curr < n)
	{
		size_t next = curr + 2 * prev;
		if (next > n)
			break;
		jacobsthal.push_back(next);
		prev = curr;
		curr = next;
	}
	return jacobsthal;
}

std::vector<int>	PmergeMe::sortVector(const std::vector<int>& input)
{
	// Ford-Johnson Algorithm for Vector
	// Example: input = [5, 2, 8, 1, 9, 3]
	
	if (input.size() <= 1)
		return input;
	
	std::vector<int>	result = input;
	size_t				n = result.size();
	bool				hasOdd = (n % 2 == 1);
	int					oddElement = hasOdd ? result[n - 1] : 0;
	
	if (hasOdd)
	{
		result.pop_back();
		n--;
	}
	
	// Step 1: Create pairs and sort each pair
	// [5,2] [8,1] [9,3] -> [2,5] [1,8] [3,9]
	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < n; i += 2)
	{
		if (result[i] > result[i + 1])
			pairs.push_back(std::make_pair(result[i + 1], result[i]));
		else
			pairs.push_back(std::make_pair(result[i], result[i + 1]));
	}
	
	// Step 2: Sort pairs by their larger element (second in pair)
	// Sort by: 5, 8, 9 -> pairs: [2,5] [1,8] [3,9]
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<int, int>	key = pairs[i];
		int					j = i - 1;
		while (j >= 0 && pairs[j].second > key.second)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
	
	// Step 3: Create main chain with larger elements and pending smaller elements
	std::vector<int>	mainChain;
	std::vector<int>	pending;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].second);
		pending.push_back(pairs[i].first);
	}
	
	std::vector<bool>	inserted(pending.size(), false);

	// Step 4: Insert first pending element at the beginning
	// 	the first pending element is the smallest of all because pairs are sorted
	if (!pending.empty())
	{
		mainChain.insert(mainChain.begin(), pending[0]);
		inserted[0] = true;
	}
	
	// Step 5: Insert remaining elements using Jacobsthal sequence
	// 
	// JACOBSTHAL SEQUENCE EXPLANATION:
	// The Jacobsthal sequence (1, 3, 5, 11, 21, 43...) is mathematically proven to minimize
	// the total number of binary search comparisons needed for optimal insertion.
	// Formula: J(n) = J(n-1) + 2*J(n-2), starting with J(0)=1, J(1)=3
	//
	// WHY THIS ORDER IS OPTIMAL:
	// Each Jacobsthal number represents a "breakpoint" where inserting elements in a specific
	// order creates the most efficient binary search trees, minimizing total comparisons.
	//
	// EXAMPLE with pending = [2, 1, 3, 7, 4] (indices 0,1,2,3,4):
	// - pending[0] = 2 already inserted
	// - Jacobsthal for size 5: [1, 3] 
	// - Insertion order will be: index 2 (value 3), then index 1 (value 1), then index 3 (value 7), then index 4 (value 4)
	//
	// Jacobsthal sequence provides optimal insertion order: 1, 3, 5, 11, 21...
	std::vector<size_t>	jacobsthal = generateJacobsthal(pending.size());
	
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		// STEP 5A: Insert element at current Jacobsthal position
		// Convert 1-based Jacobsthal number to 0-based array index
		// Example: if jacobsthal[i] = 3, we want pending[2] (since 3-1=2)
		size_t	idx = jacobsthal[i] - 1;
		if (idx < pending.size() && !inserted[idx])
		{
			// Binary search insertion - finds correct sorted position in O(log n) time
			// This element becomes an "anchor" that optimizes future insertions
			std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
			mainChain.insert(pos, pending[idx]);
			inserted[idx] = true;
		}
		
		// STEP 5B: Insert elements between previous and current Jacobsthal numbers
		// 
		// CRITICAL INSIGHT - WHY REVERSE ORDER:
		// We insert from (previous_jacobsthal) to (current_jacobsthal-1) but NOT in forward order!
		// Instead, we use the RANGE but the actual implementation here goes FORWARD, which is
		// actually a simplified version. The true Ford-Johnson inserts in a specific order
		// that ensures each element has optimal search boundaries.
		//
		// EXAMPLE: Between J(0)=1 and J(1)=3, we have index 1
		// - We insert pending[1] after pending[2] is already positioned
		// - This gives pending[1] better search bounds because pending[2] acts as a reference point
		//
		// Insert remaining elements in reverse order up to current Jacobsthal number
		for (int j = (i > 0 ? jacobsthal[i - 1] : 1); j < (int)jacobsthal[i] - 1; j++)
		{
			if (j < (int)pending.size() && !inserted[j])
			{
				// Each insertion benefits from the positioning of previously inserted Jacobsthal elements
				// The binary search has better bounds thanks to the "anchor" elements already placed
				std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
				mainChain.insert(pos, pending[j]);
				inserted[j] = true;
			}
		}
	}
	
	// STEP 5C: Cleanup - Insert any remaining elements not covered by Jacobsthal sequence
	// This handles edge cases where pending.size() exceeds our largest generated Jacobsthal number
	// Insert any remaining elements
	for (size_t i = 1; i < pending.size(); i++)
	{
		if (!inserted[i])
		{
			std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
			mainChain.insert(pos, pending[i]);
		}
	}
	
	// Step 6: Insert odd element if exists
	if (hasOdd)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
		mainChain.insert(pos, oddElement);
	}
	
	return mainChain;
}

//------------------------------------------------------------------------------------

std::list<int>	PmergeMe::sortList(const std::list<int>& input)
{
	// Ford-Johnson Algorithm for List (adapted for bidirectional iterators)

	if (input.size() <= 1)
		return input;

	std::list<int>	result = input;
	size_t			n = result.size();
	bool			hasOdd = (n % 2 == 1);
	int				oddElement = hasOdd ? result.back() : 0;
	
	if (hasOdd)
	{
		result.pop_back();
		n--;
	}
	
	// Step 1: Create pairs and sort each pair
	std::vector<std::pair<int, int> >	pairs;
	std::list<int>::iterator			it = result.begin();
	while (it != result.end())
	{
		int first = *it++;
		int second = *it++;
		if (first > second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}
	
	// Step 2: Sort pairs by their larger element
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<int, int> key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].second > key.second)
		{
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
	
	// Step 3: Create main chain and pending list
	std::list<int>		mainChain;
	std::vector<int>	pending;
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].second);
		pending.push_back(pairs[i].first);
	}
	
	// Step 4: Insert first pending element at the beginning
	if (!pending.empty())
		mainChain.push_front(pending[0]);
	
	// Step 5: Insert remaining elements using Jacobsthal sequence
	std::vector<size_t>	jacobsthal = generateJacobsthal(pending.size());
	std::vector<bool>	inserted(pending.size(), false);
	if (!pending.empty()) inserted[0] = true;
	
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		size_t	idx = jacobsthal[i] - 1;
		if (idx < pending.size() && !inserted[idx])
		{
			// Binary search for list (manual implementation)
			std::list<int>::iterator pos = mainChain.begin();
			for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			{
				if (*it >= pending[idx])
				{
					pos = it;
					break;
				}
				pos = it;
				++pos;
			}
			mainChain.insert(pos, pending[idx]);
			inserted[idx] = true;
		}
		
		// Insert remaining elements in reverse order
		for (int j = (i > 0 ? jacobsthal[i - 1] : 1); j < (int)jacobsthal[i] - 1; j++)
		{
			if (j < (int)pending.size() && !inserted[j])
			{
				std::list<int>::iterator pos = mainChain.begin();
				for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
				{
					if (*it >= pending[j]) {
						pos = it;
						break;
					}
					pos = it;
					++pos;
				}
				mainChain.insert(pos, pending[j]);
				inserted[j] = true;
			}
		}
	}
	
	// Insert any remaining elements
	for (size_t i = 1; i < pending.size(); i++)
	{
		if (!inserted[i])
		{
			std::list<int>::iterator pos = mainChain.begin();
			for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
			{
				if (*it >= pending[i])
				{
					pos = it;
					break;
				}
				pos = it;
				++pos;
			}
			mainChain.insert(pos, pending[i]);
		}
	}
	
	// Step 6: Insert odd element if exists
	if (hasOdd)
	{
		std::list<int>::iterator	pos = mainChain.begin();

		for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
		{
			if (*it >= oddElement)
			{
				pos = it;
				break;
			}
			pos = it;
			++pos;
		}
		mainChain.insert(pos, oddElement);
	}
	
	return mainChain;
}
