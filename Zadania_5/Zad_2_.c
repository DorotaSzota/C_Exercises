#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int pop_first(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty!\n");
        return -1;
    }

    struct Node* temp = *head_ref;

    *head_ref = (*head_ref)->next;

    int popped_data = temp->data;

    free(temp);

    return popped_data;
}

int main() {
    struct Node* head = NULL;

    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 420;
    node1->next = NULL;
    head = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 666;
    node2->next = NULL;
    node1->next = node2;

    int popped_value = pop_first(&head);
    if (popped_value != -1) {
        printf("The 1st element has been removed from the list: %d\n", popped_value);
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("Currently the list looks as follows: %d ", current->data);
        current = current->next;
    }

    return 0;
}

