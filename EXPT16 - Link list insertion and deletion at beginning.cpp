#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to delete the first node of the linked list
Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
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

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    cout << "Linked List after Insertion at Beginning:" << endl;
    printList(head);

    // Delete the first element
    head = deleteAtBeginning(head);

    cout << "Linked List after Deletion at Beginning:" << endl;
    printList(head);

    return 0;
}
