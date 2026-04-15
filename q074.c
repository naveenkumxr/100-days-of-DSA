/*
Day 74: Winner of an Election

Problem:
Given candidate names as votes, find the candidate with the maximum votes.
If there is a tie, choose the lexicographically smallest name.
*/

#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    struct Candidate candidates[1000];
    int size = 0;

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter %d candidate names:\n", n);
    for (int i = 0; i < n; i++) {
        char temp[100];
        int found = 0;

        scanf("%99s", temp);

        for (int j = 0; j < size; j++) {
            if (strcmp(candidates[j].name, temp) == 0) {
                candidates[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(candidates[size].name, temp);
            candidates[size].count = 1;
            size++;
        }
    }

    char winner[100];
    int maxVotes = -1;

    for (int i = 0; i < size; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].count == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
