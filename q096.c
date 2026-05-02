/*
Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].
*/

#include <stdio.h>
#include <stdlib.h>

static long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    long long count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return count;
}

static long long mergeSortCount(int arr[], int temp[], int left, int right)
{
    long long count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        count += mergeSortCount(arr, temp, left, mid);
        count += mergeSortCount(arr, temp, mid + 1, right);
        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
}

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    int *temp = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL || temp == NULL)
    {
        free(arr);
        free(temp);
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Inversion count: %I64d\n", mergeSortCount(arr, temp, 0, n - 1));

    free(arr);
    free(temp);
    return 0;
}

