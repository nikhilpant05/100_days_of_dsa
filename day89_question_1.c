/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/

#include <stdio.h>

int canAllocate(int a[], int n, int m, int limit) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (pages + a[i] > limit) {
            students++;
            pages = a[i];
            if (students > m) return 0;
        } else {
            pages += a[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > low) low = a[i];
        high += a[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(a, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}

// commit 89
