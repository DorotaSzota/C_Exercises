#include <stdlib.h>
#include <printf.h>

struct Node {
    int data;
    struct Node* next;
};

void add_first(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
int main() {
    struct Node* head = NULL;

    add_first(&head, 3);
    add_first(&head, 5);
    add_first(&head, 7);

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}


