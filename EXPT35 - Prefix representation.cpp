#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Function to evaluate a prefix expression
int evaluatePrefixExpression(string expression) {
    stack<int> operandStack;

    // Reverse the expression to start from the end
    reverse(expression.begin(), expression.end());

    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            // Operand: Push it onto the stack
            operandStack.push(stoi(token));
        } else {
            // Operator: Pop the top two operands, perform the operation, and push the result back
            int operand1 = operandStack.top();
            operandStack.pop();

            int operand2 = operandStack.top();
            operandStack.pop();

            switch (token[0]) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator: " << token << endl;
                    return 0;
            }
        }
    }

    return operandStack.top();
}

int main() {
    string expression = "- + * 2 3 * 5 4 9";
    int result = evaluatePrefixExpression(expression);
    cout << "Result of the prefix expression: " << result << endl;

    return 0;
}
