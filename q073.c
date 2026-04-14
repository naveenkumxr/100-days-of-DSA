/*
Day 73: First Non-Repeating Character

Problem:
Given a string of lowercase English letters, find the first character
that does not repeat. If all characters repeat, print '$'.
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
        freq[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("$\n");
    }

    return 0;
}
