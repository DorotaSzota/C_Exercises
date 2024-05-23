#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int remove_by_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL) {
        printf("The list is empty!\n");
        return -1;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (index == 0) {
        *head_ref = temp->next;
        int popped_data = temp->data;
        free(temp);
        return popped_data;
    }

    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        return -1;
    }

    prev->next = temp->next;
    int popped_data = temp->data;
    free(temp);

    return popped_data;
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

    int popped_value = remove_by_index(&head, 1);
    if (popped_value != -1) {
        printf("Removed element at index 1: %d\n", popped_value);
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}

