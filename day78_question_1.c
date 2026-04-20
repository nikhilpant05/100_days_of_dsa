/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

typedef struct {
    int node, key;
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
    while (i > 1 && heap[i].key < heap[i/2].key) {
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
        if (l <= size && heap[l].key < heap[smallest].key) smallest = l;
        if (r <= size && heap[r].key < heap[smallest].key) smallest = r;
        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }
}

void push(int node, int key) {
    size++;
    heap[size].node = node;
    heap[size].key = key;
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

    int key[100005], inMST[100005];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        pos[i] = 0;
    }

    key[1] = 0;
    push(1, 0);

    int total = 0;

    while (size > 0) {
        HeapNode hn = pop();
        int u = hn.node;

        if (inMST[u]) continue;
        inMST[u] = 1;
        total += hn.key;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                if (pos[v] == 0) push(v, key[v]);
                else {
                    heap[pos[v]].key = key[v];
                    heapifyUp(pos[v]);
                }
            }
            temp = temp->next;
        }
    }

    printf("%d", total);
    return 0;
}