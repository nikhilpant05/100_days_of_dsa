// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.


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

void rightView(Node* root, int level, int* maxLevel) {
    if (!root) return;

    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Node* root = build(a, n);

    int maxLevel = -1;
    rightView(root, 0, &maxLevel);

    return 0;
}