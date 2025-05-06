#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void	basicTest()
{
	std::cout << "--- Basic Test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	int shortest = sp.shortestSpan();
	int longest = sp.longestSpan();
	
	std::cout << "Shortest span: " << shortest << " (Expected: 2)" << std::endl;
	std::cout << "Longest span: " << longest << " (Expected: 14)" << std::endl;
}

void	emptySpanTest()
{
	std::cout << "\n--- Empty Span Test ---" << std::endl;
	std::cout << "Expected: Exceptions for both operations - 'Not enough numbers'" << std::endl;
	
	try
	{
		Span sp = Span(5);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		Span sp = Span(5);
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	fullSpanTest()
{
	std::cout << "\n--- Full Span Test ---" << std::endl;
	std::cout << "Expected: Exception when adding 4th number - 'Span is full'" << std::endl;
	
	Span sp = Span(3);
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "Added 3 numbers successfully." << std::endl;
		
		sp.addNumber(4); // This should throw an exception
		std::cout << "ERROR: No exception thrown!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	negativeNumbersTest()
{
	std::cout << "\n--- Negative Numbers Test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(-6);
	sp.addNumber(3);
	sp.addNumber(-17);
	sp.addNumber(9);
	sp.addNumber(-11);
	
	int shortest = sp.shortestSpan();
	int longest = sp.longestSpan();
	
	std::cout << "Shortest span: " << shortest << " (Expected: 5)" << std::endl;
	std::cout << "Longest span: " << longest << " (Expected: 26)" << std::endl;
}

void	largeSpanTest()
{
	std::cout << "\n--- Large Span Test (10,000 numbers) ---" << std::endl;
	std::cout << "Expected: Operations complete within reasonable time" << std::endl;
	
	Span sp = Span(10000);
	
	// Fill with 10,000 random numbers
	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; i++)
		sp.addNumber(rand() % 1000000);
	
	// Calculate time for operations
	clock_t start, end;
	
	start = clock();
	int shortest = sp.shortestSpan();
	end = clock();
	double shortestTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	start = clock();
	int longest = sp.longestSpan();
	end = clock();
	double longestTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	std::cout << "Shortest span: " << shortest << " (calculated in " << shortestTime << " seconds)" << std::endl;
	std::cout << "Longest span: " << longest << " (calculated in " << longestTime << " seconds)" << std::endl;
}

void	sequentialAddTest()
{
	std::cout << "\n--- Sequential Add Test ---" << std::endl;
	Span sp = Span(5);
	
	try
	{
		// Add numbers sequentially
		for (int i = 1; i <= 5; i++)
			sp.addNumber(i * 10);

		std::cout << "Successfully added 5 numbers sequentially." << std::endl;
		
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();
		
		std::cout << "Shortest span: " << shortest << " (Expected: 10)" << std::endl;
		std::cout << "Longest span: " << longest << " (Expected: 40)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	consecutiveNumbersTest()
{
	std::cout << "\n--- Consecutive Numbers Test ---" << std::endl;
	Span sp = Span(5);
	
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		sp.addNumber(5);
		
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();
		
		std::cout << "Shortest span: " << shortest << " (Expected: 1)" << std::endl;
		std::cout << "Longest span: " << longest << " (Expected: 4)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	rangeAddTest()
{
	std::cout << "\n--- Range Add Test ---" << std::endl;
	std::vector<int> numbers;
	for (int i = 1; i <= 5; i++)
		numbers.push_back(i * 10);
	
	Span sp = Span(5);
	try
	{
		sp.addNumbers(numbers);  // Now passing the vector directly
		std::cout << "Successfully added range of numbers." << std::endl;
		
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();
		
		std::cout << "Shortest span: " << shortest << " (Expected: 10)" << std::endl;
		std::cout << "Longest span: " << longest << " (Expected: 40)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	rangeAddOverflowTest()
{
	std::cout << "\n--- Range Add Overflow Test ---" << std::endl;
	std::cout << "Expected: Exception - 'Span is full'" << std::endl;
	
	std::vector<int> numbers;
	for (int i = 1; i <= 10; i++)
		numbers.push_back(i * 5);
	
	Span sp = Span(5);  // Can only hold 5 numbers
	try
	{
		// Try to add 10 numbers to a Span with capacity of 5
		sp.addNumbers(numbers);  // Now passing the vector directly
		std::cout << "ERROR: No exception thrown!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

}

int main()
{
	basicTest();
	emptySpanTest();
	fullSpanTest();
	negativeNumbersTest();
	largeSpanTest();
	sequentialAddTest();
	consecutiveNumbersTest();
	rangeAddTest();
	rangeAddOverflowTest();
	
	return (0);
}