#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void insertElementAtBeginning(int arr[], int &size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    size++;
}

void deleteElementAtBeginning(int arr[], int &size) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete elements." << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
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

        cout << "1. Insert Element at Beginning" << endl;
        cout << "2. Delete Element from Beginning" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "Enter the element to insert: ";
                cin >> element;
                insertElementAtBeginning(arr, size, element);
                break;

            case 2:
                deleteElementAtBeginning(arr, size);
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
