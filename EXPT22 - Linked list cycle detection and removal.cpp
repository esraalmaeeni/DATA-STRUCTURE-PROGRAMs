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

// Function to detect a cycle in the linked list using Floyd's Tortoise and Hare algorithm
bool hasCycle(Node* head) {
    Node* tortoise = head;
    Node* hare = head;

    while (tortoise != nullptr && hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}

// Function to remove a cycle in the linked list
void removeCycle(Node* head) {
    Node* tortoise = head;
    Node* hare = head;

    // Find the point of intersection (where the cycle starts)
    while (hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            break;
        }
    }

    // If there's no cycle, return
    if (tortoise != hare) {
        return;
    }

    // Reset one of the pointers and move both at the same pace to find the start of the cycle
    tortoise = head;
    while (tortoise->next != hare->next) {
        tortoise = tortoise->next;
        hare = hare->next;
    }

    // Remove the cycle by setting the next of the last node in the cycle to nullptr
    hare->next = nullptr;
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

    // Create a linked list with a cycle
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    
    // Create a cycle (4 -> 2)
    Node* current = head;
    while (current->data != 4) {
        current = current->next;
    }
    current->next = head->next;

    if (hasCycle(head)) {
        cout << "Linked List has a cycle." << endl;
        removeCycle(head);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle found in the Linked List." << endl;
    }

    cout << "Linked List after cycle removal:" << endl;
    printList(head);

    return 0;
}
