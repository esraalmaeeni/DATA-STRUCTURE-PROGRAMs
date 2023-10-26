#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void insertElementAtEnd(int arr[], int &size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Overflow: Array is full. Cannot insert more elements." << endl;
        return;
    }

    arr[size] = element;
    size++;
}

void deleteElementAtEnd(int arr[], int &size) {
    if (size <= 0) {
        cout << "Underflow: Array is empty. Cannot delete elements." << endl;
        return;
    }

    size--;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    int choice;
    do {
        cout << "Array Elements:";
        for (int i = 0; i < size; i++) {
            cout << " " << arr[i];
        }
        cout << endl;

        cout << "1. Insert Element at End" << endl;
        cout << "2. Delete Element from End" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "Enter the element to insert: ";
                cin >> element;
                insertElementAtEnd(arr, size, element);
                break;

            case 2:
                deleteElementAtEnd(arr, size);
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
