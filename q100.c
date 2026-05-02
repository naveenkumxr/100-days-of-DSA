/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).

Input Format
First line: n
Second line: n space-separated integers

Output Format
Print count of smaller elements on the right for each element.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Item;

static void mergeCount(Item arr[], Item temp[], int left, int mid, int right, int counts[])
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightMoved = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightMoved++;
        }
        else
        {
            counts[arr[i].index] += rightMoved;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        counts[arr[i].index] += rightMoved;
        temp[k++] = arr[i++];
    }
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
}

static void mergeSortCount(Item arr[], Item temp[], int left, int right, int counts[])
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortCount(arr, temp, left, mid, counts);
        mergeSortCount(arr, temp, mid + 1, right, counts);
        mergeCount(arr, temp, left, mid, right, counts);
    }
}

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Item *arr = (Item *)malloc((size_t)n * sizeof(Item));
    Item *temp = (Item *)malloc((size_t)n * sizeof(Item));
    int *counts = (int *)calloc((size_t)n, sizeof(int));
    if (arr == NULL || temp == NULL || counts == NULL)
    {
        free(arr);
        free(temp);
        free(counts);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    mergeSortCount(arr, temp, 0, n - 1, counts);

    printf("Counts of smaller elements on right: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", counts[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    free(arr);
    free(temp);
    free(counts);
    return 0;
}
