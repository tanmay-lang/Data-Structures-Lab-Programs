#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void push(struct Node** top, int val) {
    struct Node* n = createNode(val);
    n->next = *top;
    *top = n;
}

int pop(struct Node** top) {
    if (!*top) return -1;
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void enqueue(struct Node** front, struct Node** rear, int val) {
    struct Node* n = createNode(val);
    if (!*rear) {
        *front = *rear = n;
        return;
    }
    (*rear)->next = n;
    *rear = n;
}

int dequeue(struct Node** front) {
    if (!*front) return -1;
    struct Node* temp = *front;
    int val = temp->data;
    *front = temp->next;
    if (!*front) *rear = NULL;
    free(temp);
    return val;
}

void display(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stack = NULL, *queueFront = NULL, *queueRear = NULL;

    printf("Stack Operations:\n");
    push(&stack, 10); push(&stack, 20); push(&stack, 30);
    display(stack);
    printf("Popped: %d\n", pop(&stack));
    display(stack);

    printf("\nQueue Operations:\n");
    enqueue(&queueFront, &queueRear, 40); enqueue(&queueFront, &queueRear, 50); enqueue(&queueFront, &queueRear, 60);
    display(queueFront);
    printf("Dequeued: %d\n", dequeue(&queueFront));
    display(queueFront);

    return 0;
}
