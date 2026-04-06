/*
Day 9: Mirror the Code Name

Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
*/

#include <stdio.h>
#include <string.h>

void reverse(char str[], int index) {
    if (index < 0)
        return;

    printf("%c", str[index]);
    reverse(str, index - 1);
}

int main() {
    char str[100];

    printf("Enter code name: ");
    scanf("%s", str);

    int len = strlen(str);

    printf("Mirror format: ");
    reverse(str, len - 1);

    return 0;
}


