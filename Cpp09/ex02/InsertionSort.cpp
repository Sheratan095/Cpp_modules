#include <vector>
#include <iostream>

void	insertionSort(std::vector<int>& array)
{
	for (size_t i = 1; i < array.size(); i++)
	{
		int	temp = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}