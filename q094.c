/*
Problem: Sort array of non-negative integers using counting sort.
Find max, build frequency array, compute sorted output.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) return 1;

    int maxVal = 0;
    printf("Enter %d non-negative elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0)
        {
            free(arr);
            return 0;
        }
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int *count = (int *)calloc((size_t)(maxVal + 1), sizeof(int));
    if (count == NULL)
    {
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) count[arr[i]]++;

    printf("Sorted array: ");
    int first = 1;
    for (int value = 0; value <= maxVal; value++)
    {
        while (count[value]-- > 0)
        {
            if (!first) printf(" ");
            printf("%d", value);
            first = 0;
        }
    }
    printf("\n");

    free(count);
    free(arr);
    return 0;
}
