/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.
*/

#include <stdio.h>
#include <stdlib.h>

static int isFeasible(const int boards[], int n, int k, int maxTime)
{
    int painters = 1;
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        if (current + boards[i] > maxTime)
        {
            painters++;
            current = boards[i];
            if (painters > k)
            {
                return 0;
            }
        }
        else
        {
            current += boards[i];
        }
    }

    return 1;
}

int main(void)
{
    int n, k;
    printf("Enter number of boards and painters: ");
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k <= 0)
    {
        return 0;
    }

    int *boards = (int *)malloc((size_t)n * sizeof(int));
    if (boards == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int low = 0, high = 0;
    printf("Enter lengths of %d boards: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &boards[i]);
        if (boards[i] > low)
        {
            low = boards[i];
        }
        high += boards[i];
    }

    int answer = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isFeasible(boards, n, k, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Minimum time required: %d\n", answer);
    free(boards);
    return 0;
}
