/*
Problem: Implement Merge Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/

#include <stdio.h>
#include <stdlib.h>

static void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArray = (int *)malloc((size_t)n1 * sizeof(int));
    int *rightArray = (int *)malloc((size_t)n2 * sizeof(int));

    if (leftArray == NULL || rightArray == NULL)
    {
        free(leftArray);
        free(rightArray);
        return;
    }

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k++] = leftArray[i++];
        }
        else
        {
            arr[k++] = rightArray[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArray[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArray[j++];
    }

    free(leftArray);
    free(rightArray);
}

static void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
