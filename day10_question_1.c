// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>

int main() {
    char str[100];
    scanf("%s",str);
    int check=0;

    int count =0;
    while(str[count]!='\0'){
        count++;
    }

    for (int i=0;i<(count/2);i++){

        if (str[i]!=str[count-i-1]){
              check=0;
              break;
        }
        check=1;
       
    }

    if (check==1){
        printf("YES");
        }
    else{
        printf("NO");
        }

    return 0;
}