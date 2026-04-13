/*
Day 72: First Repeated Character

Problem:
Given a string of lowercase letters, find the first repeated character.
If no character repeats, print -1.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int found = 0;

    printf("Enter a lowercase string: ");
    scanf("%999s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        freq[index]++;

        if (freq[index] == 2) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("-1\n");
    }

    return 0;
}
