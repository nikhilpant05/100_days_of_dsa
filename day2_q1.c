/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers.
Shift remaining elements to the left.*/

#include<stdio.h>
int main(){
    int arr[50],n,i,pos;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&pos);
    for(i=pos;i<n;i++){
        arr[i-1]=arr[i];
    }
    n--;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}