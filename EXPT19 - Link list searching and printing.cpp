#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to search for a specific value in the linked list
bool searchValue(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Value found in the list
        }
        current = current->next;
    }
    return false; // Value not found in the list
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
    head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};

    cout << "Linked List:" << endl;
    printList(head);

    int searchValue1 = 3;
    if (searchValue(head, searchValue1)) {
        cout << searchValue1 << " found in the list." << endl;
    } else {
        cout << searchValue1 << " not found in the list." << endl;
    }

    int searchValue2 = 5;
    if (searchValue(head, searchValue2)) {
        cout << searchValue2 << " found in the list." << endl;
    } else {
        cout << searchValue2 << " not found in the list." << endl;
    }

    return 0;
}
