#include <iostream>

using namespace std;

// Define a structure for binary tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform an inorder traversal of a binary tree
void inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    inorderTraversal(node->left);  // Recursively traverse the left subtree
    cout << node->data << " ";     // Visit the current node
    inorderTraversal(node->right); // Recursively traverse the right subtree
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder traversal of the binary tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
