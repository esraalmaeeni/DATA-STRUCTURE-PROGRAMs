#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    int minElement;

public:
    // Constructor
    MinStack() {
        minElement = INT_MAX;
    }

    // Push an element onto the stack
    void push(int value) {
        if (value <= minElement) {
            mainStack.push(minElement);
            minElement = value;
        }
        mainStack.push(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        if (mainStack.top() == minElement) {
            mainStack.pop();
            minElement = mainStack.top();
        }
        mainStack.pop();
    }

    // Get the top element of the stack
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty." << endl;
            return -1; // Error code for an empty stack
        }
        return mainStack.top();
    }

    // Get the minimum element of the stack
    int getMin() {
        if (mainStack.empty()) {
            cout << "Stack is empty." << endl;
            return -1; // Error code for an empty stack
        }
        return minElement;
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(5);
    cout << "Minimum Element: " << stack.getMin() << endl;
    stack.push(2);
    stack.push(1);
    cout << "Minimum Element: " << stack.getMin() << endl;

    stack.pop();
    cout << "Minimum Element: " << stack.getMin() << endl;
    stack.pop();
    cout << "Top Element: " << stack.top() << endl;

    return 0;
}
