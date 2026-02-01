// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], recStack[MAX];
int n;

int dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v] && dfs(v))
                return 1;
            else if (recStack[v])
                return 1;
        }
    }

    recStack[u] = 0;
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}