// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20



#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[1000], size = 0;

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            a[size++] = x;
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min = 0;
                for (int j = 1; j < size; j++) {
                    if (a[j] < a[min]) min = j;
                }
                printf("%d\n", a[min]);
                for (int j = min; j < size - 1; j++) a[j] = a[j + 1];
                size--;
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int min = 0;
                for (int j = 1; j < size; j++) {
                    if (a[j] < a[min]) min = j;
                }
                printf("%d\n", a[min]);
            }
        }
    }
    return 0;
}