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

// Generate Jacobsthal sequence up to n
std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
    }
    
    return sequence;
}

// Generate insertion sequence based on Jacobsthal numbers
std::vector<int> generateInsertionSequence(int n) {
    std::vector<int> result;
    if (n <= 0) return result;
    
    // Calculate how many Jacobsthal numbers we need
    int jacobsthalCount = 0;
    while (generateJacobsthalSequence(jacobsthalCount).back() < n)
        jacobsthalCount++;
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(jacobsthalCount);
    
    // Start with position 1 (first small element)
    result.push_back(1);
    
    // Follow Jacobsthal sequence
    for (size_t i = 3; i + 1 < jacobsthal.size(); i++) {
        int start = jacobsthal[i];
        int end = std::min(n, jacobsthal[i+1]);
        
        // Add elements in reverse order
        for (int j = start; j > end; j--) {
            if (j <= n) result.push_back(j);
        }
    }
    
    // Add any remaining positions
    for (int i = 1; i <= n; i++) {
        if (std::find(result.begin(), result.end(), i) == result.end()) {
            result.push_back(i);
        }
    }
    
    return result;
}

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
    
    // Step 1: Create pairs alreay sorted
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
    
    // Step 5: Insert smaller elements using binary insertion with Jacobsthal sequence
    // Insert the first smaller element
    if (!pairs.empty())
        insertWithBinarySearch(result, pairs[0].second);
        
    // Generate insertion sequence based on Jacobsthal numbers
    std::vector<int> insertionOrder = generateInsertionSequence(pairs.size());
    
    // Insert the rest according to Jacobsthal sequence
    for (size_t i = 1; i < insertionOrder.size() && i < pairs.size(); i++) {
        int idx = insertionOrder[i] - 1; // Convert to 0-indexed
        if (idx < static_cast<int>(pairs.size()))
            insertWithBinarySearch(result, pairs[idx].second);
    }
    
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
    
    // Step 5: Insert smaller elements using binary insertion with Jacobsthal sequence
    // Insert the first smaller element if pairs exist
    if (!pairs.empty()) {
        std::list<int>::iterator position = result.begin();
        while (position != result.end() && *position < pairs[0].second)
            ++position;
        result.insert(position, pairs[0].second);
    }
    
    // Generate insertion sequence based on Jacobsthal numbers
    std::vector<int> insertionOrder = generateInsertionSequence(pairs.size());
    
    // Insert the rest according to Jacobsthal sequence
    for (size_t i = 1; i < insertionOrder.size() && i < pairs.size(); i++) {
        int idx = insertionOrder[i] - 1; // Convert to 0-indexed
        if (idx < static_cast<int>(pairs.size())) {
            int element_to_insert = pairs[idx].second;
            
            // Find insertion position using binary search concept
            std::list<int>::iterator position = result.begin();
            while (position != result.end() && *position < element_to_insert)
                ++position;
            
            result.insert(position, element_to_insert);
        }
    }
    
    // Step 6: Insert the odd element if exists
    if (has_odd) {
        std::list<int>::iterator position = result.begin();
        while (position != result.end() && *position < odd_element)
            ++position;
        result.insert(position, odd_element);
    }
    
    return result;
}
