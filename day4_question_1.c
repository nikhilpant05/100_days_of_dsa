// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the reversed array, space-separated

// Example:
// Input:
// 5
// 1 2 3 4 5

// Output:
// 5 4 3 2 1

// Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays.

#include <stdio.h>

int main() {
    int arr[100],n,x;

    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int i=0,j=n-1,t;
    while (i<j){
        t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++,j--;
    }

    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    
    }

    return 0;
}// commit 4
