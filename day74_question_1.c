/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate,
determine the candidate who received the maximum number of votes. 
In case of a tie, return the lexicographically smallest candidate name.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];
    int count[1000] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        char temp[50];
        scanf("%s", temp);

        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}