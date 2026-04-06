/*
Day 56: Symmetric Binary Tree Check

Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }

    struct Node* nodes[200] = {NULL};
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            nodes[i] = createNode(arr[i]);
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

    return nodes[0];
}

int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) {
        return 1;
    }
    if (left == NULL || right == NULL) {
        return 0;
    }
    if (left->data != right->data) {
        return 0;
    }

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

int main() {
    printf("Enter input:\n");
    int n;
    scanf("%d", &n);

    int arr[200];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    if (root == NULL || isMirror(root->left, root->right)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}



