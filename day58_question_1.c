// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.


#include <stdio.h>

#define MAX 1000

int pre[MAX], in[MAX];

void printPostorder(int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return;

    int root = pre[preStart];

    int idx = inStart;
    while (in[idx] != root)
        idx++;

    int leftSize = idx - inStart;

    printPostorder(preStart + 1, preStart + leftSize, inStart, idx - 1);
    printPostorder(preStart + leftSize + 1, preEnd, idx + 1, inEnd);

    printf("%d ", root);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    printPostorder(0, n - 1, 0, n - 1);

    return 0;
}