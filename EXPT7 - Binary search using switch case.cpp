#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the size of the sorted array: ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    cout << "Enter " << size << " sorted elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1) {
        cout << "Element found at position " << result << " (0-based index)." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
