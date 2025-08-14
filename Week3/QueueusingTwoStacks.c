#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push onto stack
void push1(int val) { stack1[++top1] = val; }
void push2(int val) { stack2[++top2] = val; }

// Pop from stack
int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

// Move all elements from stack1 to stack2
void transfer() {
    while (top1 >= 0) {
        push2(pop1());
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
            // Enqueue
            scanf("%d", &x);
            push1(x);
        }
        else if (type == 2) {
            // Dequeue
            if (top2 < 0) transfer();
            if (top2 >= 0) pop2();
        }
        else if (type == 3) {
            // Print front
            if (top2 < 0) transfer();
            if (top2 >= 0) printf("%d\n", stack2[top2]);
        }
    }
    return 0;
}
