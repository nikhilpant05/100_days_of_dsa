/*Problem: Implement Binary Search Iterative - Implement the algorithm.

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
    int n, x;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            ans = mid;
            break;
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}// commit 87
