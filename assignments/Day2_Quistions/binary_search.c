#include <stdio.h>
int binary_search (int *arr, int arr_len, int key)
{
	int counter = 0;
	int start = 0, end = arr_len - 1;
	int mid = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (key == arr[mid])
			return mid;
		else if (key > arr[mid])
			start = mid + 1;
		else
			end = mid - 1;
    }

	return -1;
}


int main (void)
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num;
	while (1)
	{
		printf ("Please enter the number you want to search for\n");
		fflush (stdout);
		scanf ("%d", &num);
		fflush (stdin);
		printf ("the index of the number is: %d\n", binary_search (arr, 10, num));
		fflush (stdout);
		}

}
