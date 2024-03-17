#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
};

struct Contact addressBook[MAX_CONTACTS];
int numContacts = 0;

void addContact(const char *firstName, const char *lastName, const char *phoneNumber) {
    if (numContacts < MAX_CONTACTS) {
        strcpy(addressBook[numContacts].firstName, firstName);
        strcpy(addressBook[numContacts].lastName, lastName);
        strcpy(addressBook[numContacts].phoneNumber, phoneNumber);
        numContacts++;
        printf("Contact added successfully.\n");
    } else {
        printf("Address book is full. Cannot add more contacts.\n");
    }
}

void findContact(const char *lastName) {
    int found = 0;
    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(addressBook[i].lastName, lastName) == 0) {
            printf("Contact found:\n");
            printf("First Name: %s\n", addressBook[i].firstName);
            printf("Last Name: %s\n", addressBook[i].lastName);
            printf("Phone Number: %s\n", addressBook[i].phoneNumber);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact with last name '%s' not found.\n", lastName);
    }
}

void removeContact(const char *lastName) {
    int found = 0;
    for (int i = 0; i < numContacts; ++i) {
        if (strcmp(addressBook[i].lastName, lastName) == 0) {
            found = 1;
            // Shift remaining contacts to fill the gap
            for (int j = i; j < numContacts - 1; ++j) {
                addressBook[j] = addressBook[j + 1];
            }
            numContacts--;
            printf("Contact removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact with last name '%s' not found.\n", lastName);
    }
}

void printContacts() {
    printf("Address Book:\n");
    for (int i = 0; i < numContacts; ++i) {
        printf("%d. %s %s - %s\n", i + 1, addressBook[i].firstName, addressBook[i].lastName, addressBook[i].phoneNumber);
    }
}

int main() {
    int choice;
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a contact\n");
        printf("2. Find a contact\n");
        printf("3. Remove a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter first name: ");
                scanf("%s", firstName);
                printf("Enter last name: ");
                scanf("%s", lastName);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                addContact(firstName, lastName, phoneNumber);
                break;
            case 2:
                printf("Enter last name to find: ");
                scanf("%s", lastName);
                findContact(lastName);
                break;
            case 3:
                printf("Enter last name to remove: ");
                scanf("%s", lastName);
                removeContact(lastName);
                break;
            case 4:
                printContacts();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    }

    return 0;
}
