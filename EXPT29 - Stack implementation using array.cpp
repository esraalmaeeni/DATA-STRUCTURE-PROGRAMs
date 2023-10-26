#include <iostream>
using namespace std;

class Stack {
private:
    int* array;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        array = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        array[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Error code for an empty stack
        }
        int popped = array[top--];
        return popped;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    stack.push(4);
    stack.push(5);

    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << endl;
    }

    return 0;
}
