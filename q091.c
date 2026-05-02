/*
Problem: Implement merge sort (divide, sort halves, merge).
Print sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

static void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *a = (int *)malloc((size_t)n1 * sizeof(int));
    int *b = (int *)malloc((size_t)n2 * sizeof(int));
    if (a == NULL || b == NULL)
    {
        free(a);
        free(b);
        return;
    }

    for (int i = 0; i < n1; i++) a[i] = arr[left + i];
    for (int j = 0; j < n2; j++) b[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];

    free(a);
    free(b);
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
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) return 1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    free(arr);
    return 0;
}
