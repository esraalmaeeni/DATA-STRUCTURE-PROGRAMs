#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void insertElement(int arr[], int &size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int &size, int position) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete elements." << endl;
        return;
    }

    if (position < 0 || position >= size) {
        cout << "Invalid position for deletion." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
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

        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element, position;
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position to insert: ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;

            case 2:
                cout << "Enter the position to delete: ";
                cin >> position;
                deleteElement(arr, size, position);
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
