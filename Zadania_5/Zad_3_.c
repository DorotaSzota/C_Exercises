#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int remove_last(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty!\n");
        return -1;
    }

    if ((*head_ref)->next == NULL) {
        int popped_data = (*head_ref)->data;
        free(*head_ref);
        *head_ref = NULL;
        return popped_data;
    }

    struct Node* current = *head_ref;
    while (current->next->next != NULL) {
        current = current->next;
    }

    int popped_data = current->next->data;

    free(current->next);

    current->next = NULL;

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

    int popped_value = remove_last(&head);
    if (popped_value != -1) {
        printf("The last element on the list has been removed: %d\n", popped_value);
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("Currently the list looks as follows: %d ", current->data);
        current = current->next;
    }

    return 0;
}

