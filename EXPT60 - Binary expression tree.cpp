#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Define a structure for binary expression tree nodes
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if a string is an operator (+, -, *, /)
bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// Function to evaluate the expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (!isOperator(root->value)) {
        return stoi(root->value);
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    if (root->value == "+") {
        return leftValue + rightValue;
    } else if (root->value == "-") {
        return leftValue - rightValue;
    } else if (root->value == "*") {
        return leftValue * rightValue;
    } else {
        // Assume that division by zero is not allowed in this example
        return leftValue / rightValue;
    }
}

// Function to build a binary expression tree from a postfix expression
TreeNode* buildExpressionTree(const string& postfix) {
    stack<TreeNode*> st;

    for (char c : postfix) {
        string s(1, c);

        if (!isOperator(s)) {
            st.push(new TreeNode(s));
        } else {
            TreeNode* right = st.top();
            st.pop();
            TreeNode* left = st.top();
            st.pop();

            TreeNode* newNode = new TreeNode(s);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }

    return st.top();
}

int main() {
    string postfixExpression = "34*5+";

    TreeNode* root = buildExpressionTree(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = evaluateExpressionTree(root);

    cout << "Result of Evaluation: " << result << endl;

    return 0;
}
