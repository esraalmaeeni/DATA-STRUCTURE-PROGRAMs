#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at a specific position in the linked list
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Invalid position. Node not inserted." << endl;
        delete newNode;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to delete a node at a specific position in the linked list
Node* deleteAtPosition(Node* head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position. Node not deleted." << endl;
        return head;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at various positions
    head = insertAtPosition(head, 1, 1); // Position 1
    head = insertAtPosition(head, 3, 2); // Position 2
    head = insertAtPosition(head, 2, 2); // Position 2

    cout << "Linked List after Insertion at Positions:" << endl;
    printList(head);

    // Delete elements at various positions
    head = deleteAtPosition(head, 2); // Delete position 2

    cout << "Linked List after Deletion at Position:" << endl;
    printList(head);

    return 0;
}
