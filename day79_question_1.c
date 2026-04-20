/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

Edge* adj[100005];
HeapNode heap[100005];
int pos[100005];
int size;

void swap(int i, int j) {
    HeapNode t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
    pos[heap[i].node] = i;
    pos[heap[j].node] = j;
}

void heapifyUp(int i) {
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

void heapifyDown(int i) {
    int l, r, smallest;
    while (1) {
        l = 2*i;
        r = 2*i + 1;
        smallest = i;
        if (l <= size && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }
}

void push(int node, int dist) {
    size++;
    heap[size].node = node;
    heap[size].dist = dist;
    pos[node] = size;
    heapifyUp(size);
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size];
    pos[heap[1].node] = 1;
    size--;
    heapifyDown(1);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Edge* e = (Edge*)malloc(sizeof(Edge));
        e->v = v;
        e->w = w;
        e->next = adj[u];
        adj[u] = e;

        e = (Edge*)malloc(sizeof(Edge));
        e->v = u;
        e->w = w;
        e->next = adj[v];
        adj[v] = e;
    }

    int source;
    scanf("%d", &source);

    int dist[100005];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        pos[i] = 0;
    }

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode hn = pop();
        int u = hn.node;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (pos[v] == 0) {
                    push(v, dist[v]);
                } else {
                    heap[pos[v]].dist = dist[v];
                    heapifyUp(pos[v]);
                }
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}