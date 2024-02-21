#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to be swap.
 * @b: The second integer to be swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t v, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (v = 0; v < len - 1; v++)
		{
			if (array[v] > array[v + 1])
			{
				swap_ints(array + v, array + v + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
