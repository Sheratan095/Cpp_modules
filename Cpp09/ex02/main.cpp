
#include <iostream>

void mergeSort(int array[], int lenght);

int main()
{
	int array[] = {3, 7, 8, 5, 4, 2, 6, 1};

	int len = 8;

	for(int i = 0; i < len; i++)
		std::cout << array[i] << std::endl;

	mergeSort(array, len);
	std::cout << std::endl;


	for(int i = 0; i < len; i++)
		std::cout << array[i] << std::endl;

}
