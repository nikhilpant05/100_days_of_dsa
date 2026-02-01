

// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.


#include <stdio.h>

#define MAX 1000

int in[MAX], post[MAX];

void printPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
        return;

    int root = post[postEnd];

    int idx = inStart;
    while (in[idx] != root)
        idx++;

    int leftSize = idx - inStart;

    printf("%d ", root);

    printPreorder(inStart, idx - 1, postStart, postStart + leftSize - 1);
    printPreorder(idx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    printPreorder(0, n - 1, 0, n - 1);

    return 0;
}