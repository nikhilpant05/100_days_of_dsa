// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored
//.


#include <stdio.h>

int main() {
    char str[100];
    scanf("%s",str);

    int count =0;
    while(str[count]!='\0'){
        count++;

    }

    for (int i =0;i<((count-1)/2);i++){
        char a;
        a=str[i];
        str[i]=str[count-1-i];
        str[count-1-i]=a;
    }

    printf("%s",str);
    return 0;
}