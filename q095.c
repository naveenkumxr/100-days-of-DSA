/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *values;
    int size;
    int capacity;
} Bucket;

static int floatCompare(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    float *arr = (float *)malloc((size_t)n * sizeof(float));
    Bucket *buckets = (Bucket *)calloc((size_t)n, sizeof(Bucket));
    if (arr == NULL || buckets == NULL)
    {
        free(arr);
        free(buckets);
        return 1;
    }

    printf("Enter %d float values in [0,1): ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        if (arr[i] < 0.0f || arr[i] >= 1.0f)
        {
            free(arr);
            free(buckets);
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = (int)(arr[i] * n);
        Bucket *bucket = &buckets[index];
        if (bucket->size == bucket->capacity)
        {
            int newCapacity = (bucket->capacity == 0) ? 4 : bucket->capacity * 2;
            float *newValues = (float *)realloc(bucket->values, (size_t)newCapacity * sizeof(float));
            if (newValues == NULL)
            {
                for (int j = 0; j < n; j++) free(buckets[j].values);
                free(buckets);
                free(arr);
                return 1;
            }
            bucket->values = newValues;
            bucket->capacity = newCapacity;
        }
        bucket->values[bucket->size++] = arr[i];
    }

    printf("Sorted array: ");
    int first = 1;
    for (int i = 0; i < n; i++)
    {
        if (buckets[i].size > 0)
        {
            qsort(buckets[i].values, (size_t)buckets[i].size, sizeof(float), floatCompare);
            for (int j = 0; j < buckets[i].size; j++)
            {
                if (!first) printf(" ");
                printf("%.2f", buckets[i].values[j]);
                first = 0;
            }
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++) free(buckets[i].values);
    free(buckets);
    free(arr);
    return 0;
}
