

// Problem Statement:
// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

// Example:
// Input:
// 7
// 1 2 2 3 4 4 3

// Output:
// YES

// Explanation:
// Left subtree is a mirror image of the right subtree.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* build(int a[], int n) {
    Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = NULL;

    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            nodes[i] = create(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    return nodes[0];
}

int isMirror(Node* a, Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->data != b->data) return 0;

    return isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Node* root = build(a, n);

    if (!root) {
        printf("YES");
        return 0;
    }

    if (isMirror(root->left, root->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}