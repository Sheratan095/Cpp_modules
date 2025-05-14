#include <iostream>
#include <vector>

// Forward declaration (since no header file)
void mergeSort(std::vector<int>& array);

int main()
{
	std::vector<int>	arr;
	int	input[] = {38, 27, 43, 3, 9, 82, 10};
	for (size_t i = 0; i < sizeof(input)/sizeof(input[0]); ++i)
		arr.push_back(input[i]);

	mergeSort(arr);

	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return (0);
}
