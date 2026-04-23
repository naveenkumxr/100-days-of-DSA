/*
Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)

Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5

Explanation:
For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
- The lower bound is at index 2, which is the first occurrence of 4.
- The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
Binary Search is used to find both bounds efficiently in O(log n) time.
*/

#include <stdio.h>
#include <stdlib.h>

static int lowerBound(const int arr[], int n, int x)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

static int upperBound(const int arr[], int n, int x)
{
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
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

    int x;
    printf("Enter target value: ");
    if (scanf("%d", &x) != 1)
    {
        free(arr);
        return 0;
    }

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower bound index and upper bound index: %d %d\n", lb, ub);

    free(arr);
    return 0;
}
