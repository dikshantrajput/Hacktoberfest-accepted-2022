#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int value;
    Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory to a node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // insert the data
    new_node -> value = new_data;
    new_node -> next = (*head_ref); 

    // Move head to new node
    (*head_ref) = new_node;    
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> value = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 

    new_node -> value = new_data;
    new_node -> next = NULL;

    if (*head_ref == NULL) 
        *head_ref = new_node;
    return ;

    while (last -> next != NULL) last = last -> next;

    last -> next = new_node; 
    return;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp -> value == key) {
        *head_ref = temp -> next;
        free(temp); 
        return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp -> value != key) {
        prev = temp;
        temp = temp -> next;
    }

    // if the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev -> next = temp -> next;

    free(temp);
}

bool searchNode (struct Node** head_ref, int key) {
    struct Node* current = *head_ref; 
    while (current != NULL) {
        if (current -> value == key) return true;
        current = current -> next;
    }
    return false;
}

void sortLinkedList(struct Node** head_ref) {
    struct Node *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL) return;
    else {
        while (current != NULL) {
            // index points to the node next to current
            index = current -> next;

            while (index != NULL) {
                if (current -> value > index -> value) {
                    temp = current -> value;
                    current -> value = index -> value;
                    index -> value = temp;
                }
                index = index -> next;
            }
            current = current -> next;
        }
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node -> value << ' ';
        node = node -> next;
    }
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAfter(head->next, 5);

    cout << "Linked list: ";
    printList(head);

    cout << "\nAfter deleting an element: ";
    deleteNode(&head, 3);
    printList(head);

    int item_to_find = 3;

    if (searchNode(&head, item_to_find)) {
        cout << endl << item_to_find << " is found";
    } 
    else {
        cout << endl << item_to_find << " is not found";
    }   

    sortLinkedList(&head);
    cout << "\nSorted List: ";
    printList(head);

    return 0;
}
