#include <iostream>
#include <vector>
#include <ctime> // for clock_t, clock(), CLOCKS_PER_SEC

// Forward declarations
void mergeSort(std::vector<int>& array);
void insertionSort(std::vector<int>& array);

int main()
{
	std::vector<int>	arr;
	int	input[] = {38, 27, 43, 3, 9, 82, 10};
	for (size_t i = 0; i < sizeof(input)/sizeof(input[0]); ++i)
		arr.push_back(input[i]);

	// Copies of the array for each sort
	std::vector<int>	arr_merge = arr;
	std::vector<int>	arr_insert = arr;

	// Time merge sort
	clock_t start_merge = clock();
	mergeSort(arr_merge);
	clock_t end_merge = clock();
	double time_merge = static_cast<double>(end_merge - start_merge) / CLOCKS_PER_SEC;
	std::cout << "Merge sort took " << time_merge << " seconds.\n";

	// Time insertion sort
	clock_t start_insert = clock();
	insertionSort(arr_insert);
	clock_t end_insert = clock();
	double time_insert = static_cast<double>(end_insert - start_insert) / CLOCKS_PER_SEC;
	std::cout << "Insertion sort took " << time_insert << " seconds.\n";

	return 0;
}
