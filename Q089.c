/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/

#include <stdio.h>
#include <stdlib.h>

static int isFeasible(const int pages[], int n, int students, int maxPages)
{
    int requiredStudents = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentSum + pages[i] > maxPages)
        {
            requiredStudents++;
            currentSum = pages[i];

            if (requiredStudents > students)
            {
                return 0;
            }
        }
        else
        {
            currentSum += pages[i];
        }
    }

    return 1;
}

int main(void)
{
    int n, m;

    printf("Enter number of books and students: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0)
    {
        return 0;
    }

    int *pages = (int *)malloc((size_t)n * sizeof(int));
    if (pages == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int low = 0;
    int high = 0;

    printf("Enter pages in %d books: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
        if (pages[i] > low)
        {
            low = pages[i];
        }
        high += pages[i];
    }

    if (n < m)
    {
        printf("Minimum possible maximum pages: -1\n");
        free(pages);
        return 0;
    }

    int answer = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isFeasible(pages, n, m, mid))
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Minimum possible maximum pages: %d\n", answer);

    free(pages);
    return 0;
}
