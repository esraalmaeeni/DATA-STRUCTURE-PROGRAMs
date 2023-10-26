#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define a structure for binary tree nodes
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to convert preorder to postorder
vector<int> preorderToPostorder(vector<int>& preorder) {
    int n = preorder.size();
    if (n == 0) {
        return vector<int>();
    }

    // The first element in the preorder is the root in postorder
    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);
    stack<TreeNode*> st;
    st.push(root);

    vector<int> postorder;

    // Reconstruct the tree and create the postorder traversal
    for (int i = 1; i < n; i++) {
        TreeNode* node = st.top();
        TreeNode* newNode = new TreeNode(preorder[i]);
        while (!st.empty() && st.top()->val < preorder[i]) {
            node = st.top();
            st.pop();
        }

        if (node->val > preorder[i]) {
            node->left = newNode;
        } else {
            node->right = newNode;
        }

        st.push(newNode);
    }

    // Create the postorder traversal by traversing the reconstructed tree
    stack<TreeNode*> postorderStack;
    postorderStack.push(root);
    while (!postorderStack.empty()) {
        TreeNode* node = postorderStack.top();
        postorderStack.pop();
        postorder.push_back(node->val);
        if (node->left) {
            postorderStack.push(node->left);
        }
        if (node->right) {
            postorderStack.push(node->right);
        }
    }

    return postorder;
}

int main() {
    vector<int> preorder = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> postorder = preorderToPostorder(preorder);

    cout << "Postorder traversal: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
