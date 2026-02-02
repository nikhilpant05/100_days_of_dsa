/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space*/

#include<stdio.h>
int main(){
    int arr[50],n,i,pos,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&pos);
    scanf("%d",&x);
    for(i=n-1;i>pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=x;
    n++;
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}