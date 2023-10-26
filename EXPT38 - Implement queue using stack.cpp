#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1; // For enqueue operation
    stack<int> s2; // For dequeue operation

public:
    // Enqueue (add) an element to the queue
    void enqueue(int value) {
        s1.push(value);
    }

    // Dequeue (remove) an element from the queue
    int dequeue() {
        if (s2.empty()) {
            // Transfer elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Error code for an empty queue
        }

        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingStacks queue;

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
