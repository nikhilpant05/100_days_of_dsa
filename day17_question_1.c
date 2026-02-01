// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1


#include <stdio.h>

int main() {
    
    int arr[100],n;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int max=arr[0];
    int min=arr[0];

    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }

        if(min>arr[i]){
            min=arr[i];
        }

    }


    printf("Max: %d\n",max);
    printf("Min: %d",min);
    

    return 0;
}