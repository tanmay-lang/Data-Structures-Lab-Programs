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

void insertEnd(struct Node** head, int val) {
    struct Node* n = createNode(val);
    if (!*head) {
        *head = n;
        return;
    }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
}

void display(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node** head) {
    for (struct Node *i = *head; i && i->next; i = i->next)
        for (struct Node *j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    struct Node* t = l1;
    while (t->next) t = t->next;
    t->next = l2;
    return l1;
}

int main() {
    struct Node *l1 = NULL, *l2 = NULL;

    insertEnd(&l1, 3); insertEnd(&l1, 1); insertEnd(&l1, 5); insertEnd(&l1, 2);
    insertEnd(&l2, 10); insertEnd(&l2, 8); insertEnd(&l2, 12);

    printf("List 1: "); display(l1);
    printf("List 2: "); display(l2);

    sortList(&l1);
    printf("Sorted List 1: "); display(l1);

    reverseList(&l2);
    printf("Reversed List 2: "); display(l2);

    struct Node* l3 = concatenate(l1, l2);
    printf("Concatenated List: "); display(l3);

    return 0;
}
