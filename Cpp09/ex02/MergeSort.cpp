#include <vector>
#include <iostream>

void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result);

void mergeSort(std::vector<int>& array)
{
	// base case
	if (array.size() <= 1)
		return ;

	size_t	middle = array.size() / 2;

	// populate the vectors
	std::vector<int>	left(array.begin(), array.begin() + middle); // from start to middle
	std::vector<int>	right(array.begin() + middle, array.end()); // from middle to end

	mergeSort(left);
	mergeSort(right);

	merge(left, right, array);
}

void	merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result)
{
	result.clear();

	size_t	l = 0;// for left array
	size_t	r = 0;// for right array

	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r])
			result.push_back(left[l++]);
		else // right[r] > left[l]
			result.push_back(right[r++]);
	}

	while (l < left.size())
		result.push_back(left[l++]);

	while (r < right.size())
		result.push_back(right[r++]);
}
