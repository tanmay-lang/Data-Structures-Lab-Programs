#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(struct Node** head, int val) {
    struct Node* n = createNode(val);
    if (!*head) {
        *head = n;
        return;
    }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertLeft(struct Node** head, int target, int val) {
    struct Node* t = *head;
    while (t && t->data != target) t = t->next;
    if (!t) return;
    struct Node* n = createNode(val);
    n->next = t;
    n->prev = t->prev;
    if (t->prev) t->prev->next = n;
    else *head = n;
    t->prev = n;
}

void deleteNode(struct Node** head, int val) {
    struct Node* t = *head;
    while (t && t->data != val) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else *head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void display(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* dll = NULL;

    insertEnd(&dll, 10);
    insertEnd(&dll, 20);
    insertEnd(&dll, 30);
    printf("Doubly Linked List: ");
    display(dll);

    insertLeft(&dll, 20, 15);
    printf("After Inserting 15 to the left of 20: ");
    display(dll);

    deleteNode(&dll, 10);
    printf("After Deleting 10: ");
    display(dll);

    return 0;
}
