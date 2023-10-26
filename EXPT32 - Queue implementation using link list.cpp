#include <iostream>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue (add) an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued." << endl;
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Error code for an empty queue
        }
        int dequeued = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return dequeued;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    queue.enqueue(4);
    queue.enqueue(5);

    while (!queue.isEmpty()) {
        cout << "Dequeued: " << queue.dequeue() << endl;
    }

    return 0;
}
