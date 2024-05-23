#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int insert_at_index(struct Node** head_ref, int index, int new_data) {
    if (index < 0) {
        printf("Invalid index!\n");
        return 0;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation error!\n");
        return 0;
    }

    new_node->data = new_data;

    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return 1;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        free(new_node);
        return 0;
    }

    new_node->next = temp->next;
    temp->next = new_node;

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

    int inserted = insert_at_index(&head, 2, 6);
    if (inserted) {
        printf("Inserted new element with value 6 at index 2.\n");
    } else {
        printf("Failed to insert new element at index 2.\n");
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}

