/*Problem: Implement linear search to find key k in an array.
Count and display the number of comparisons performed.*/

#include<stdio.h>
int main(){
    int arr[50],n,i,k,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    for(i=0;i<n;i++){
        c++;
        if(arr[i]==k){
            printf("Found at index %d\n",i);
            break;
        }
    }
    printf("Comparisons = %d",c);
}