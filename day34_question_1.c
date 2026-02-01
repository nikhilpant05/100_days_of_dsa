// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack *createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = s->top;
    s->top = node;
}

int pop(Stack *s) {
    if (s->top == NULL) exit(1);
    Node *temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

int main() {
    Stack *s = createStack();
    char token[64];

    while (scanf("%s", token) == 1) {
        if (strlen(token) == 1 && !isdigit(token[0]) && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int b = pop(s);
            int a = pop(s);
            int result;
            if (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else result = a / b;
            push(s, result);
        } else {
            push(s, atoi(token));
        }
    }

    printf("%d\n", pop(s));

    while (s->top) pop(s);
    free(s);

    return 0;
}