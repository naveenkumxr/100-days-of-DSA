/*
Day 8: Compute Power Using Recursion

Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/

#include <stdio.h>

int power(int a, int b) {
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    scanf("%d", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    if (b < 0) {
        printf("This program does not handle negative powers.\n");
    } else {
        printf("%d^%d = %d\n", a, b, power(a, b));
    }

    return 0;
}


