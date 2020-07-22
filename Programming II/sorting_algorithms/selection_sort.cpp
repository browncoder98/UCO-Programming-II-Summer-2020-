void swap(int *array, int i, int k);
void selection_sort(int *data, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min_index = i;
		for (int k = i + 1; k < size; k++)
		{
			// find min_index
			if (data[k] < data[min_index])
			{
				min_index = k;
			}
		}
		// found min value at min_index
		swap(data, i, min_index);
	}
}

void swap(int *array, int i, int k)
{
	int temp = array[i];
	array[i] = array[k];
	array[k] = temp;
}