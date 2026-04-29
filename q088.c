/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/

#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

static int canPlaceCows(const int stalls[], int n, int k, int minDistance)
{
    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPosition >= minDistance)
        {
            count++;
            lastPosition = stalls[i];
        }

        if (count >= k)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int n, k;

    printf("Enter number of stalls and cows: ");
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k <= 0 || k > n)
    {
        return 0;
    }

    int *stalls = (int *)malloc((size_t)n * sizeof(int));
    if (stalls == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d stall positions: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    qsort(stalls, (size_t)n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Maximum possible minimum distance: %d\n", answer);

    free(stalls);
    return 0;
}
