#include "sort.h"

void swap_ints(int *t, int *p);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @t: The first integer to swap.
 * @p: The second integer to swap.
 */
void swap_ints(int *t, int *p)
{
	int tmp;

	tmp = *t;
	*t = *p;
	*p = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *rise, high, low;

	rise = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *rise)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *rise)
	{
		swap_ints(array + high, rise);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pat;

	if (right - left > 0)
	{
		pat = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pat - 1);
		lomuto_sort(array, size, pat + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
