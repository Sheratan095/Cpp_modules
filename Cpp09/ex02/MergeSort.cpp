#include <iostream>

static void merge(int leftArray[], int rightArray[], int array[], int leftSize, int rightSize);

void mergeSort(int array[], int size)
{
	if (size <= 1)
		return;

	int middle = size / 2;
	int leftSize = middle;
	int rightSize = size - middle;

	int leftArray[leftSize];
	int rightArray[rightSize];

	for (int i = 0; i < size; ++i)
	{
		if (i < middle)
			leftArray[i] = array[i];
		else
			rightArray[i - middle] = array[i];
	}

	mergeSort(leftArray, leftSize);
	mergeSort(rightArray, rightSize);
	merge(leftArray, rightArray, array, leftSize, rightSize);
}

static void merge(int leftArray[], int rightArray[], int array[], int leftSize, int rightSize)
{
	int i = 0, l = 0, r = 0;

	while (l < leftSize && r < rightSize)
	{
		if (leftArray[l] < rightArray[r])
			array[i++] = leftArray[l++];
		else
			array[i++] = rightArray[r++];
	}

	while (l < leftSize)
		array[i++] = leftArray[l++];

	while (r < rightSize)
		array[i++] = rightArray[r++];
}
