#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
void createList(struct Node **head);
void displayList(struct Node *head);
void insertAtBeginning(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void insertBeforeNode(struct Node **head, int target, int data);
void insertAfterNode(struct Node **head, int target, int data);
void deleteFromBeginning(struct Node **head);
void deleteFromEnd(struct Node **head);
void deleteAfterNode(struct Node **head, int target);
void deleteEntireList(struct Node **head);

int main() {
    struct Node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the elements of the doubly linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire doubly linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                printf("Enter the target node data: ");
                scanf("%d", &target);
                printf("Enter the data to insert before %d: ", target);
                scanf("%d", &data);
                insertBeforeNode(&head, target, data);
                break;
            case 6:
                printf("Enter the target node data: ");
                scanf("%d", &target);
                printf("Enter the data to insert after %d: ", target);
                scanf("%d", &data);
                insertAfterNode(&head, target, data);
                break;
            case 7:
                deleteFromBeginning(&head);
                break;
            case 8:
                deleteFromEnd(&head);
                break;
            case 9:
                printf("Enter the target node data: ");
                scanf("%d", &target);
                deleteAfterNode(&head, target);
                break;
            case 10:
                deleteEntireList(&head);
                break;
            case 11:
                deleteEntireList(&head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void createList(struct Node **head) {
    int data;
    char choice;
    do {
        printf("Enter data for the node: ");
        scanf("%d", &data);
        insertAtEnd(head, data);
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
void insertBeforeNode(struct Node **head, int target, int data) {
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}
void insertAfterNode(struct Node **head, int target, int data) {
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}


void deleteAfterNode(struct Node **head, int target) {
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Node after data %d not found.\n", target);
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
}


void deleteEntireList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("The entire list has been deleted.\n");
}
