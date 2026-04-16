/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
First line contains the number of elements in the array.
Second line contains the array elements.

Output Format
Print the length of the longest subarray with sum equal to zero.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    long long *prefix = (long long *)malloc(n * sizeof(long long));
    int *firstIndex = (int *)malloc(n * sizeof(int));

    if (arr == NULL || prefix == NULL || firstIndex == NULL)
    {
        printf("Memory allocation failed.\n");
        free(arr);
        free(prefix);
        free(firstIndex);
        return 1;
    }

    printf("Enter %d array elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxLength = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefix[i] = sum;
        firstIndex[i] = -1;

        if (sum == 0)
        {
            maxLength = i + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (firstIndex[i] != -1)
        {
            continue;
        }

        firstIndex[i] = i;
        for (int j = i + 1; j < n; j++)
        {
            if (prefix[j] == prefix[i])
            {
                int length = j - firstIndex[i];
                if (length > maxLength)
                {
                    maxLength = length;
                }
            }
        }
    }

    printf("Length of the largest zero sum subarray: %d\n", maxLength);

    free(arr);
    free(prefix);
    free(firstIndex);
    return 0;
}
