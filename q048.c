/*
Day 48: Count Leaf Nodes

Problem: Count Leaf Nodes

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

int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    printf("Enter input:\n");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int values[200];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    if (values[0] == -1) {
        printf("0\n");
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

    printf("%d\n", countLeaves(nodes[0]));
    return 0;
}



