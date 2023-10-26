#include <iostream>

using namespace std;

// Define a structure for binary tree nodes
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to search for a value in a BST
TreeNode* search(TreeNode* root, int target) {
    if (root == nullptr || root->val == target) {
        return root;
    }

    if (target < root->val) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

// Function to check if a value exists in a BST
bool valueExists(TreeNode* root, int target) {
    TreeNode* result = search(root, target);
    return (result != nullptr);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    int target = 3;

    if (valueExists(root, target)) {
        cout << "Value " << target << " exists in the BST." << endl;
    } else {
        cout << "Value " << target << " does not exist in the BST." << endl;
    }

    return 0;
}
