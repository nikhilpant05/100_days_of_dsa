//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include<stdio.h>
int main(){
    int arr[50],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x=0;
    for(i=0;i<n/2;i++){
        x=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=x;
    }
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}