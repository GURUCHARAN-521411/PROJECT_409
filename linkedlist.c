/*Aim:
Write c program on linked list for the follwing terms insertion first,deletion first,insertion last ,deletion last ,insertion random,deletion random,search,update. 


Explanation:
Insertion at the beginning: Adds a node at the start of the list.
Deletion from the beginning: Removes the node at the start of the list.
Insertion at the end: Adds a node at the end of the list.
Deletion from the end: Removes the node at the end of the list.
Insertion at a random position: Adds a node at any specified position.
Deletion from a random position: Removes a node at any specified position.
Search: Searches for an element in the list and displays its position.
Update: Updates the value of a node at a specified position.
Display: Displays the entire list.

CODE:*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
void insertFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to delete from the beginning
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted the first element\n");
}

// Function to insert at the end
void insertLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
}

// Function to delete from the end
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Deleted the last element\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted the last element\n");
}

// Function to insert at a random position
void insertRandom(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    struct Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
}

// Function to delete from a random position
void deleteRandom(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("List is empty or invalid position\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Deleted element at position %d\n", position);
        return;
    }

    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted element at position %d\n", position);
}

// Function to search an element in the list
void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

// Function to update an element at a specific position
void update(struct Node* head, int position, int newData) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    temp->data = newData;
    printf("Updated element at position %d to %d\n", position, newData);
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements
    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertLast(&head, 30);
    insertLast(&head, 40);
    display(head);

    // Deleting elements
    deleteFirst(&head);
    deleteLast(&head);
    display(head);

    // Inserting at random positions
    insertRandom(&head, 25, 2);
    insertRandom(&head, 35, 4);
    display(head);

    // Deleting at random positions
    deleteRandom(&head, 2);
    display(head);

    // Search
    search(head, 25);
    search(head, 50);

    // Update
    update(head, 2, 50);
    display(head);

    return 0;
}

/*OUTPUT:

Inserted 10 at the beginning
Inserted 20 at the beginning
Inserted 30 at the end
Inserted 40 at the end
20 -> 10 -> 30 -> 40 -> NULL
Deleted the first element
Deleted the last element
10 -> 30 -> NULL
Inserted 25 at position 2
Inserted 35 at position 4
10 -> 25 -> 30 -> 35 -> NULL
Deleted element at position 2
10 -> 30 -> 35 -> NULL
Element 25 not found in the list
Element 50 not found in the list
Updated element at position 2 to 50
10 -> 50 -> 35 -> NULL*/
