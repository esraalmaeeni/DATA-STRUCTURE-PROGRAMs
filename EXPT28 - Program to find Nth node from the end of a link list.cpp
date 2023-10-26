#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to find the Nth node from the end of the linked list
Node* findNthFromEnd(Node* head, int n) {
    if (head == nullptr || n <= 0) {
        return nullptr;
    }

    Node* firstPtr = head;
    Node* secondPtr = head;

    // Move the first pointer N nodes ahead
    for (int i = 0; i < n; i++) {
        if (firstPtr == nullptr) {
            return nullptr; // N is greater than the length of the list
        }
        firstPtr = firstPtr->next;
    }

    // Move both pointers together until the first pointer reaches the end
    while (firstPtr != nullptr) {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }

    return secondPtr;
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

    // Insert elements into the linked list
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Linked List:" << endl;
    printList(head);

    int n = 3;
    Node* nthNode = findNthFromEnd(head, n);

    if (nthNode != nullptr) {
        cout << "Nth node from the end (N = " << n << "): " << nthNode->data << endl;
    } else {
        cout << "Nth node from the end not found." << endl;
    }

    return 0;
}
