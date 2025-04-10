#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
	Array<int> numbe;

	Array<float> numbers(10);

	Array<float> test(numbers);

	for (float i = 0; i < 10; i++)
		numbers[i] = i / 2;

	for (float i = 0; i < 10; i++)
		std::cout << numbers[i] << std::endl;

	std::cout << numbers.size() << std::endl;

	return (0);
}