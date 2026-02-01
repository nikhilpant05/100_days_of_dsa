

// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO


#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX];
int n;

int dfs(int u, int parent) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                if (dfs(v, u))
                    return 1;
            } else if (v != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}