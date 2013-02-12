void swap(int array[], int i, int j) 
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void quickSort(int array[], int start, int end)
{
	int i = start;
	int j = end;
	int offset = rand() % (end - start + 1);
	int x = start + offset;
	while (i < j)
	{
		while ((i < x) && (array[i] <= array[x]))
		{
			++i;
		}
		while ((j > x) && (array[j] > array[x]))
		{
			--j;
		}
		if (i != j)
		{
			swap(array, i, j);
			if (i == x)
			{
				x = j;
			}
			else if (j == x)
			{
				x = i;
			}
		}
	}
	if (x != start) 
	{
		quickSort(array, start, x - 1);
	}
	if (x != end)
	{
		quickSort(array, x + 1, end);
	}
}
