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

// Function to print the top view of a binary tree
void topView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    map<int, int> topViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->val;
        }

        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (const auto& entry : topViewMap) {
        cout << entry.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    cout << "Top view of the binary tree: ";
    topView(root);

    return 0;
}
