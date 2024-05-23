#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int remove_by_value(struct Node** head_ref, int value) {
    if (*head_ref == NULL) {
        printf("The list is empty!\n");
        return 0;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element with value %d not found\n", value);
        return 0;
    }

    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *head_ref = temp->next;
    }

    free(temp);

    return 1;
}

int main() {
    struct Node* head = NULL;

    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 3;
    node1->next = NULL;
    head = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 5;
    node2->next = NULL;
    node1->next = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 7;
    node3->next = NULL;
    node2->next = node3;

    int removed = remove_by_value(&head, 5);
    if (removed) {
        printf("Removed first element with value 5.\n");
    } else {
        printf("Failed to remove element with value 5.\n");
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}

