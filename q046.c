/*
Day 46: Level Order Traversal

Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    printf("Enter input:\n");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    int values[200];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    if (values[0] == -1) {
        return 0;
    }

    struct Node* nodes[200] = {NULL};
    for (int i = 0; i < n; i++) {
        if (values[i] != -1) {
            nodes[i] = createNode(values[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n) {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }

    struct Node* queue[200];
    int front = 0, rear = 0;
    queue[rear++] = nodes[0];
    int first = 1;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (!first) {
            printf(" ");
        }
        printf("%d", current->data);
        first = 0;

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    printf("\n");
    return 0;
}



