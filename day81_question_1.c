/*Problem: Implement Bubble Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}// commit 81
