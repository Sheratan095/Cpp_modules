#include "Date.hpp"
#include "BitcoinExchange.hpp"
#include <iostream>

void dateTests();

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string inputFile = argv[1];
	try
	{
		BitcoinExchange exchange("data.csv");
		exchange.parseInputFile(inputFile);	
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: exception thrown: " << e.what() << std::endl;
		return (1);
	}
}

void dateTests()
{
	std::cout << "=== Testing Date Constructor ===" << std::endl;
	
	// Test valid dates
	try
	{
		std::cout << "\n--- Valid Dates ---" << std::endl;
		
		Date date1("2022-10-01");
		std::cout << "Test 1 passed: " << date1.toString() << std::endl;
		
		Date date2("2023-01-31");
		std::cout << "Test 2 passed: " << date2.toString() << std::endl;
		
		Date date3("2020-02-29"); // Leap year
		std::cout << "Test 3 passed (leap year): " << date3.toString() << std::endl;
		
		Date date4("2023-12-31");
		std::cout << "Test 4 passed: " << date4.toString() << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cerr << "ERROR: Valid date test failed: " << e.what() << std::endl;
	}
	
	// Test invalid dates
	std::cout << "\n--- Invalid Dates ---" << std::endl;
	
	// Invalid format
	try
	{
		Date invalid1("20231005"); // Missing hyphens
		std::cout << "ERROR: Test failed - invalid format accepted" << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cout << "Test 5 passed: caught exception for invalid format: " << e.what() << std::endl;
	}
	
	// Invalid month
	try
	{
		Date invalid2("2023-13-01"); // Month > 12
		std::cout << "ERROR: Test failed - invalid month accepted" << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cout << "Test 6 passed: caught exception for invalid month: " << e.what() << std::endl;
	}
	
	// Invalid day
	try
	{
		Date invalid3("2023-04-31"); // April has 30 days
		std::cout << "ERROR: Test failed - invalid day accepted" << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cout << "Test 7 passed: caught exception for invalid day: " << e.what() << std::endl;
	}
	
	// Invalid leap year
	try
	{
		Date invalid4("2023-02-29"); // 2023 is not a leap year
		std::cout << "ERROR: Test failed - invalid leap year date accepted" << std::endl;
	}
	catch (const Date::InvalidDateException &e)
	{
		std::cout << "Test 8 passed: caught exception for invalid leap year: " << e.what() << std::endl;
	}
}