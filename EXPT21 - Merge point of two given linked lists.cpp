#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Function to find the length of a linked list
int findLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to find the merge point of two linked lists
Node* findMergePoint(Node* head1, Node* head2) {
    int length1 = findLength(head1);
    int length2 = findLength(head2);

    Node* current1 = head1;
    Node* current2 = head2;

    // Move the longer list's pointer ahead by the difference in lengths
    if (length1 > length2) {
        for (int i = 0; i < length1 - length2; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < length2 - length1; i++) {
            current2 = current2->next;
        }
    }

    // Traverse both lists until they meet at the merge point
    while (current1 != current2) {
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1; // Return the merge point
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
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{2, nullptr};
    head1->next->next = new Node{3, nullptr};
    head1->next->next->next = new Node{4, nullptr};

    Node* head2 = new Node{9, nullptr};
    head2->next = new Node{10, nullptr};

    // Make head2 merge with head1 at node with value 3
    head2->next->next = head1->next->next;

    cout << "Linked List 1:" << endl;
    printList(head1);

    cout << "Linked List 2:" << endl;
    printList(head2);

    Node* mergePoint = findMergePoint(head1, head2);

    if (mergePoint != nullptr) {
        cout << "Merge Point Value: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
