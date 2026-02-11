/*Problem: A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order.
Your task is to create a single chronological log that preserves the correct order of arrivals.
*/
/*Problem: A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order.
Your task is to create a single chronological log that preserves the correct order of arrivals.
*/

#include <stdio.h>

int main() {
    int log1[100], log2[100], merged[200];
    int p, q;
    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    int i = 0, j = 0, k = 0;

    while(i < p && j < q) {
        if(log1[i] < log2[j]) {
            merged[k] = log1[i];
            i++;
        } else {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    while(i < p) {
        merged[k] = log1[i];
        i++;
        k++;
    }

    while(j < q) {
        merged[k] = log2[j];
        j++;
        k++;
    }

    for(int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }
    return 0;
}
