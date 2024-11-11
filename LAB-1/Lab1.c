#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;


void push(int item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
        printf("Item %d pushed to stack\n", item);
    }
}


int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        printf("Item %d popped from stack\n", stack[top]);
        return stack[top--];
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, item;

    while (1) {
        printf("\n1: Push\n2: Pop\n3: Display\n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

