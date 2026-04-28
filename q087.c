/*
Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated sorted integers
- Third line: target element to search

Output:
- Print the index of the target if found, otherwise print -1

Example:
Input:
5
12 22 25 34 64
25

Output:
2
*/

#include <stdio.h>
#include <stdlib.h>

static int binarySearchIterative(const int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter target element: ");
    if (scanf("%d", &target) != 1)
    {
        free(arr);
        return 0;
    }

    printf("%d\n", binarySearchIterative(arr, n, target));

    free(arr);
    return 0;
}
