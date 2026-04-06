/*
Day 59: Build Tree from Inorder & Postorder

Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int postIndex;

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int rootValue = postorder[postIndex--];
    struct Node* root = createNode(rootValue);

    if (start == end) {
        return root;
    }

    int inIndex = search(inorder, start, end, rootValue);
    root->right = buildTree(inorder, postorder, inIndex + 1, end);
    root->left = buildTree(inorder, postorder, start, inIndex - 1);

    return root;
}

void preorderPrint(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    printf("Enter input:\n");
    int n;
    scanf("%d", &n);

    int inorder[200], postorder[200];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1);
    preorderPrint(root);
    printf("\n");
    return 0;
}



