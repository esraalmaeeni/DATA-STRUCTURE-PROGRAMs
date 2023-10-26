#include <iostream>
#include <stack>

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

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single element list is a palindrome
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the linked list using the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    stack<int> secondHalf;
    while (slow != nullptr) {
        secondHalf.push(slow->data);
        slow = slow->next;
    }

    // Compare the first half with the reversed second half
    slow = head;
    while (!secondHalf.empty()) {
        if (slow->data != secondHalf.top()) {
            return false; // Not a palindrome
        }
        slow = slow->next;
        secondHalf.pop();
    }

    return true; // Palindrome
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

    // Insert elements into the linked list to form a palindrome
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);

    cout << "Linked List (Palindrome):" << endl;
    printList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
