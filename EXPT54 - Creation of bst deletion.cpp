#include <iostream>

using namespace std;

// Define a structure for binary tree nodes
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given value from a BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the in-order successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the in-order successor's content to this node
        root->val = temp->val;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

// Function to perform an in-order traversal of the BST
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original BST: ";
    inOrderTraversal(root);
    cout << endl;

    // Delete a node (e.g., node with value 3)
    root = deleteNode(root, 3);

    cout << "BST after deleting node with value 3: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
