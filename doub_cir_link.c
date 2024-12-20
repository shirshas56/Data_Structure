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
void deleteFromBeginning(struct Node **head);
void deleteFromEnd(struct Node **head);
void deleteAfterNode(struct Node **head, int target);
void deleteEntireList(struct Node **head);

int main() {
    struct Node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular doubly linked list\n");
        printf("2. Display the elements of the circular doubly linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular doubly linked list\n");
        printf("9. Exit\n");
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
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter the target node data: ");
                scanf("%d", &target);
                deleteAfterNode(&head, target);
                break;
            case 8:
                deleteEntireList(&head);
                break;
            case 9:
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
    printf("Circular doubly linked list: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node *last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
    } else {
        struct Node *last = temp->prev;
        *head = temp->next;
        (*head)->prev = last;
        last->next = *head;
        free(temp);
    }
}
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *last = (*head)->prev;
    if (last == *head) {
        *head = NULL;
        free(last);
    } else {
        struct Node *secondLast = last->prev;
        secondLast->next = *head;
        (*head)->prev = secondLast;
        free(last);
    }
}
void deleteAfterNode(struct Node **head, int target) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    do {
        if (temp->data == target) {
            struct Node *nodeToDelete = temp->next;
            if (nodeToDelete == *head) {
                printf("No node exists after the specified node in circular fashion.\n");
                return;
            }
            temp->next = nodeToDelete->next;
            nodeToDelete->next->prev = temp;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Node with data %d not found.\n", target);
}

void deleteEntireList(struct Node **head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
    printf("The entire list has been deleted.\n");
}
