

// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.


#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int a[MAX];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && a[i] > a[l]) {
            printf("NO");
            return 0;
        }

        if (r < n && a[i] > a[r]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}