#include <iostream>
#include <map>
#include <queue>

using namespace std;

// Define a structure for binary tree nodes
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to print the bottom view of a binary tree
void bottomView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    map<int, int> bottomViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        bottomViewMap[hd] = node->val;

        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (const auto& entry : bottomViewMap) {
        cout << entry.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    cout << "Bottom view of the binary tree: ";
    bottomView(root);

    return 0;
}
