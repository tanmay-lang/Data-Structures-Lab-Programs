#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int circularQueue[MAX];
int front = -1, rear = -1;


void insert(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {  
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {  
        rear = 0;
    } else {
        rear++;
    }
    circularQueue[rear] = value;
    printf("Inserted %d into the queue\n", value);
}


void delete() {
    if (front == -1) {  
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    printf("Deleted %d from the queue\n", circularQueue[front]);
    if (front == rear) {  
        front = rear = -1;
    } else if (front == MAX - 1) {  
        front = 0;
    } else {
        front++;
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", circularQueue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", circularQueue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", circularQueue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
