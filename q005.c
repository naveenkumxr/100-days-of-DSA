/*
Day 5: Arrange Arrival Logs

Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/

#include <stdio.h>

void mergeLogs(int arrA[], int nA, int arrB[], int nB, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < nA && j < nB) {
        if (arrA[i] <= arrB[j]) {
            merged[k] = arrA[i];
            i++;
        } else {
            merged[k] = arrB[j];
            j++;
        }
        k++;
    }

    while (i < nA) {
        merged[k++] = arrA[i++];
    }

    while (j < nB) {
        merged[k++] = arrB[j++];
    }
}

int main() {
    printf("Enter input:\n");
    int logA[] = {101, 105, 110, 120}; 
    int logB[] = {102, 108, 115};      
    int nA = sizeof(logA) / sizeof(logA[0]);
    int nB = sizeof(logB) / sizeof(logB[0]);
    int merged[nA + nB];

    mergeLogs(logA, nA, logB, nB, merged);

    printf("Chronological Merged Log: \n");
    for (int i = 0; i < nA + nB; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}



