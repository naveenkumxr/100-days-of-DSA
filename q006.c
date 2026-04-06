/*
Day 6: Remove Duplicates from Sorted Array

Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;          
            arr[i] = arr[j]; 
        }
    }

    return i + 1;
}

int main() {
    printf("Enter input:\n");
    int arr[] = {10, 20, 20, 30, 33, 33, 33, 40, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array size: %d\n", n);

    int newSize = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNew size: %d\n", newSize);

    return 0;
}



