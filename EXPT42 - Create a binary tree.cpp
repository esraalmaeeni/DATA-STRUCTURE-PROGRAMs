#include <iostream>

using namespace std;

// Define a structure for binary tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a sample binary tree
Node* createBinaryTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return root;
}

// Function to print the binary tree using an in-order traversal
void inOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

int main() {
    Node* root = createBinaryTree();

    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
