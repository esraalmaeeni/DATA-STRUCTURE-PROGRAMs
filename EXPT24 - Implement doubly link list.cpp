#include <iostream>

using namespace std;

// Define a structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;

    if (head == nullptr) {
        newNode->next = nullptr;
    } else {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to print the doubly linked list forwards
void printListForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to print the doubly linked list backwards
void printListBackward(Node* head) {
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at the beginning
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Insert elements at the end
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    cout << "Doubly Linked List (Forward):" << endl;
    printListForward(head);

    cout << "Doubly Linked List (Backward):" << endl;
    printListBackward(head);

    return 0;
}
