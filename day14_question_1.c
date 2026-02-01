// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix
#include <stdio.h>

int main() {
    int arr[10][10],m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if ((i==j)&&(arr[i][i]!=1)||(i!=j)&&(arr[i][j]!=0)){
              printf("Not an Identity Matrix");
              return 0;
            }


        }
    }

    printf("Identity Matrix ");
  


    return 0;
}