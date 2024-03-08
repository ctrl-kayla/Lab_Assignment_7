/* Kayla Butler
COP 3502 Section 3
Lab Assignment 7
6 March 2024 */
#include <stdio.h>

void swap (int *x, int *y) // Simple swap funtion
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort (int arr[], int n) // Sort numbers using the Bubble sort algorithm
{
    int totalSwaps = 0; // Total number of swaps
    int valueSwaps[n]; // Array to store number of swaps for each value
    
    for(int i = 0; i < n; i++)
    {
        valueSwaps[i] = 0; // Initalize array to 0
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int swaps = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // If current element is greater then the next element
            {
                swap(&arr[j], &arr[j + 1]); // Swap the two elements
                valueSwaps[j]++;
                swaps++; // Incrument total swaps
            }
        }
        totalSwaps += swaps;

    }
        for (int i = 0; i < n; i++)
        {
            printf("%d: # of times %d is swapped\n", valueSwaps[i]/2, arr[i]); // Prints number of swaps for each indiviudal element
        }
    printf("\nTotal # of  bubble sort swaps: %d\n", totalSwaps); // Prints total number of swaps

}

void selection_sort (int arr[], int n) // Sort numbers using the Selection sort algorithm
{
    int totalSwaps = 0; // Total number of swaps
    int valueSwaps[n]; // Array to store number of swaps for each value
    
    for(int i = 0; i < n; i++)
    {
        valueSwaps[i] = 0; // Initalize array to 0
    }

    for (int i = 0; i < n - 1; i++)
    {
        // find min ( i to n - 1)
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
      swap(&arr[min_idx], &arr[i]);
      valueSwaps[min_idx]++;
      totalSwaps++; // Increment total swaps
    }
    for (int i = 0; i < n; i++)
        {
            printf("%d: # of times %d is swapped\n", valueSwaps[i]/2, arr[i]); // prints number of swaps for each individual elelment
        }
    printf("\nTotal # of selection sort swaps: %d\n", totalSwaps); // Prints total number of swaps
}

int main() 
{
    int n = 9; // Number of integers in each gvien array

    // Given arrays
    int array1[] = {97,16, 45,63,13,22,7,58,72};
    int array2[] = {90,80,70,60,50,40,30,20,10};

    printf("Array 1:\n");
    bubble_sort(array1, n);
    printf("\n");
    selection_sort(array1, n);
    printf("\n");

    printf("Array 2:\n");
    bubble_sort(array2, n);
    printf("\n");
    selection_sort(array2, n);
    printf("\n");

    return 0;
}