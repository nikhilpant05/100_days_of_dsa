// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>

int main() {
    int arr[100], n;
    int p[100] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (p[i] == 1)
            continue;

        int c;

        for(int j = i+1;j <n;j++) {
            if (arr[i]==arr[j]) {
                c++;
                p[j]=1;
            }
        }

        printf("%d:%d",arr[i],c);
    }

    return 0;
}
