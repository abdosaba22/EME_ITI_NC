#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"


void swap(u32* a, u32* b)
{
	u32 t = *a;
	*a = *b;
	*b = t;
}

u32 partition(u32 *arr, u32 low, u32 high)
{
	u32 pivot = arr[high];
	u32 j,i = (low - 1);
	
	for (j = low; j <= high - 1; j++) 
	{
		if (arr[j] <= pivot) 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


u32 quickSort(u32 *arr, u32 low, u32 high)
{
	if (low < high) {
		u32 pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main()
{
	u32 arr[] = { 10, 7, 8, 9, 1, 5 ,12};
	u32 i,N = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, N - 1);

	printf("Sorted array: \n");

	for ( i = 0; i < N; i++)
	{	
		printf("%d ", arr[i]);
	}
	return 0;
}
