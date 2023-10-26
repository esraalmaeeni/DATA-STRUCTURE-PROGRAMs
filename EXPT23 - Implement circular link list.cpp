#include <iostream>

using namespace std;

// Define a structure for a circular linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the circular linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode; // Point to itself if it's the only node
        return newNode;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
    return head;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << " (Back to Head)" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements into the circular linked list
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    cout << "Circular Linked List:" << endl;
    printList(head);

    return 0;
}
