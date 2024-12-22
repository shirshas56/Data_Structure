#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;      
    }

    return prev; 
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("The linked list is empty.\n");
        return 0;
    }
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("Original linked list: ");
    printList(head);
    head = reverseLinkedList(head);
    printf("Reversed linked list: ");
    printList(head);
    return 0;
}
