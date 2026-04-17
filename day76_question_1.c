/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

#include <stdio.h>
#include <stdlib.h>

int** adj;
int* sizes;
int* visited;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < sizes[node]; i++) {
        int nei = adj[node][i];
        if (!visited[nei]) dfs(nei);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    adj = malloc((n + 1) * sizeof(int*));
    sizes = calloc(n + 1, sizeof(int));
    visited = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) adj[i] = malloc((n + 1) * sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][sizes[u]++] = v;
        adj[v][sizes[v]++] = u;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}