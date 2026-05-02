/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.

Assumed Input Format
First line: n
Next n lines: start end
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

static int compareIntervals(const void *a, const void *b)
{
    const Interval *x = (const Interval *)a;
    const Interval *y = (const Interval *)b;
    if (x->start != y->start) return x->start - y->start;
    return x->end - y->end;
}

int main(void)
{
    int n;
    printf("Enter number of intervals: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Interval *arr = (Interval *)malloc((size_t)n * sizeof(Interval));
    if (arr == NULL) return 1;

    printf("Enter %d intervals (start end):\n", n);
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].start, &arr[i].end);

    qsort(arr, (size_t)n, sizeof(Interval), compareIntervals);

    printf("Merged intervals:\n");
    int currentStart = arr[0].start;
    int currentEnd = arr[0].end;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start <= currentEnd)
        {
            if (arr[i].end > currentEnd) currentEnd = arr[i].end;
        }
        else
        {
            printf("%d %d\n", currentStart, currentEnd);
            currentStart = arr[i].start;
            currentEnd = arr[i].end;
        }
    }
    printf("%d %d\n", currentStart, currentEnd);

    free(arr);
    return 0;
}
