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

// Function to convert postorder to preorder
vector<int> postorderToPreorder(vector<int> &postorder) {
    int n = postorder.size();
    if (n == 0) {
        return vector<int>();
    }

    // The last element in the postorder is the root in preorder
    int rootVal = postorder[n - 1];
    TreeNode* root = new TreeNode(rootVal);
    stack<TreeNode*> st;
    st.push(root);

    vector<int> preorder;
    
    // Reconstruct the tree and create the preorder traversal
    for (int i = n - 2; i >= 0; i--) {
        TreeNode* node = st.top();
        TreeNode* newNode = new TreeNode(postorder[i]);
        while (!st.empty() && st.top()->val > postorder[i]) {
            node = st.top();
            st.pop();
        }
        
        if (node->val < postorder[i]) {
            node->right = newNode;
        } else {
            node->left = newNode;
        }
        
        st.push(newNode);
    }

    // Create the preorder traversal by traversing the reconstructed tree
    stack<TreeNode*> preorderStack;
    preorderStack.push(root);
    while (!preorderStack.empty()) {
        TreeNode* node = preorderStack.top();
        preorderStack.pop();
        preorder.push_back(node->val);
        if (node->right) {
            preorderStack.push(node->right);
        }
        if (node->left) {
            preorderStack.push(node->left);
        }
    }

    return preorder;
}

int main() {
    vector<int> postorder = {1, 3, 2, 6, 9, 8, 4, 5};

    vector<int> preorder = postorderToPreorder(postorder);

    cout << "Preorder traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
