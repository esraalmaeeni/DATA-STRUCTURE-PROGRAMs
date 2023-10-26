#include <iostream>
#include <algorithm>

using namespace std;

// Define a structure for binary tree nodes
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the height of a binary tree
int heightOfBinaryTree(Node* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(root->left, diameter);
    int rightHeight = heightOfBinaryTree(root->right, diameter);

    // Update the diameter if a new longest path is found
    diameter = max(diameter, leftHeight + rightHeight + 1);

    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of a binary tree
int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    heightOfBinaryTree(root, diameter);
    return diameter;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int treeDiameter = diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << treeDiameter << endl;

    return 0;
}
