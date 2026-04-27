/*
Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8

Input:
20

Output:
4

Input:
1

Output:
1
*/

#include <stdio.h>

static int integerSqrt(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int low = 1;
    int high = n;
    int answer = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n)
        {
            return (int)mid;
        }
        else if (square < n)
        {
            answer = (int)mid;
            low = (int)mid + 1;
        }
        else
        {
            high = (int)mid - 1;
        }
    }

    return answer;
}

int main(void)
{
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        return 0;
    }

    printf("Integer square root: %d\n", integerSqrt(n));
    return 0;
}
