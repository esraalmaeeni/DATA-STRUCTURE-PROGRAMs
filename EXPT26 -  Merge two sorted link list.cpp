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

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    Node* mergedHead = nullptr;
    Node* current = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            if (mergedHead == nullptr) {
                mergedHead = current = head1;
            } else {
                current->next = head1;
                current = head1;
            }
            head1 = head1->next;
        } else {
            if (mergedHead == nullptr) {
                mergedHead = current = head2;
            } else {
                current->next = head2;
                current = head2;
            }
            head2 = head2->next;
        }
    }

    if (head1 != nullptr) {
        if (mergedHead == nullptr) {
            mergedHead = head1;
        } else {
            current->next = head1;
        }
    }

    if (head2 != nullptr) {
        if (mergedHead == nullptr) {
            mergedHead = head2;
        } else {
            current->next = head2;
        }
    }

    return mergedHead;
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
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Insert elements into the first linked list
    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 3);
    head1 = insertAtEnd(head1, 5);

    // Insert elements into the second linked list
    head2 = insertAtEnd(head2, 2);
    head2 = insertAtEnd(head2, 4);
    head2 = insertAtEnd(head2, 6);

    cout << "Linked List 1:" << endl;
    printList(head1);

    cout << "Linked List 2:" << endl;
    printList(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);

    cout << "Merged Sorted List:" << endl;
    printList(mergedHead);

    return 0;
}
