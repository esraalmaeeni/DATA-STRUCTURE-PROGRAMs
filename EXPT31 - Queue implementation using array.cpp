#include <iostream>
using namespace std;

class Queue {
private:
    int* array;
    int capacity;
    int front;
    int rear;

public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] array;
    }

    // Enqueue (add) an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = value;
        cout << value << " enqueued." << endl;
    }

    // Dequeue (remove) an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Error code for an empty queue
        }
        int dequeued = array[front];
        front = (front + 1) % capacity;
        return dequeued;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % capacity == front);
    }
};

int main() {
    Queue queue(5);

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
