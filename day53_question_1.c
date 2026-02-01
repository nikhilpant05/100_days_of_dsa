// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int hd;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    n->hd = 0;
    return n;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    if (!root) return 0;

    QNode queue[n];
    int front = 0, rear = 0;

    int min = 0, max = 0;

    queue[rear++] = (QNode){root, 0};

    int map[2000][200];
    int count[2000] = {0};

    while (front < rear) {
        QNode temp = queue[front++];
        Node* node = temp.node;
        int hd = temp.hd;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        int idx = hd + 1000;
        map[idx][count[idx]++] = node->data;

        if (node->left)
            queue[rear++] = (QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (QNode){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }

    return 0;
}