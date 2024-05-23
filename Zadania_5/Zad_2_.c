#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int pop_first(struct Node** head_ref) {
    // Sprawdzenie, czy lista nie jest pusta
    if (*head_ref == NULL) {
        printf("Lista jest pusta!\n");
        return -1; // Zwróć -1, aby wskazać błąd w przypadku próby usunięcia z pustej listy
    }

    // Utworzenie tymczasowego wskaźnika na pierwszy element
    struct Node* temp = *head_ref;

    // Przestawienie głowy na drugi element listy
    *head_ref = (*head_ref)->next;

    // Pobranie danych z pierwszego elementu
    int popped_data = temp->data;

    // Zwolnienie pamięci zajmowanej przez pierwszy element
    free(temp);

    return popped_data; // Zwrócenie wartości usuwanego elementu
}

int main() {
    struct Node* head = NULL;

    // Dodanie kilku elementów do listy
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 3;
    node1->next = NULL;
    head = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 5;
    node2->next = NULL;
    node1->next = node2;

    // Usunięcie pierwszego elementu z listy
    int popped_value = pop_first(&head);
    if (popped_value != -1) {
        printf("Usunięto pierwszy element: %d\n", popped_value);
    }

    // Wyświetlenie listy po usunięciu pierwszego elementu
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}

