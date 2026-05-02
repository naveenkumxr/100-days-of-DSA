/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use a min-heap or equivalent overlap counting logic.

Assumed Input Format
First line: n
Next n lines: start end
*/

#include <stdio.h>
#include <stdlib.h>

static int compareInt(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

int main(void)
{
    int n;
    printf("Enter number of meetings: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *start = (int *)malloc((size_t)n * sizeof(int));
    int *end = (int *)malloc((size_t)n * sizeof(int));
    if (start == NULL || end == NULL)
    {
        free(start);
        free(end);
        return 1;
    }

    printf("Enter %d meeting intervals (start end):\n", n);
    for (int i = 0; i < n; i++) scanf("%d %d", &start[i], &end[i]);

    qsort(start, (size_t)n, sizeof(int), compareInt);
    qsort(end, (size_t)n, sizeof(int), compareInt);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        if (start[i] < end[j])
        {
            rooms++;
            if (rooms > maxRooms) maxRooms = rooms;
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    printf("Minimum meeting rooms required: %d\n", maxRooms);
    free(start);
    free(end);
    return 0;
}
