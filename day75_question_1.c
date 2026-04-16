/*Problem Statement
Given an array of integers containing both positive and negative values, 
find the length of the longest contiguous subarray whose sum is equal to zero.
*/

#include <stdio.h>

int maxLen(int arr[], int n)
{
    int max_len = 0, sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == 0)
            {
                if(j - i + 1 > max_len)
                    max_len = j - i + 1;
            }
        }
    }
    return max_len;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", maxLen(arr, n));

    return 0;
}