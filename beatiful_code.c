/**
 * function_array - function of all the elements of an integer array.
 * @array: The integer array.
 * @size: The size of the array.
 *
 * Return: The function of all the elements in the array.
 */
int sum_array(int *array, size_t size)
{
	int sum = 0;
	size_t m;

	if (array == NULL || size == 0)
	return (0);

	for (i = 0; m < size; m++)
	{
	sum += array[m];
	}

	return (sum);
}
