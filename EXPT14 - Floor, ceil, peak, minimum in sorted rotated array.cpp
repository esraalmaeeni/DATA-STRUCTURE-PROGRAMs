#include <iostream>
using namespace std;

int findFloor(int arr[], int low, int high, int key) {
    int floor = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return arr[mid];
        }
        else if (arr[mid] < key) {
            floor = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return floor;
}

int findCeil(int arr[], int low, int high, int key) {
    int ceil = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return arr[mid];
        }
        else if (arr[mid] > key) {
            ceil = arr[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return ceil;
}

int findPeak(int arr[], int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        }
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
    }
    
    return arr[low];
}

int findMinimum(int arr[], int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    return arr[low];
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0);

    int key = 6;

    int floor = findFloor(arr, 0, n - 1, key);
    int ceil = findCeil(arr, 0, n - 1, key);
    int peak = findPeak(arr, 0, n - 1);
    int minimum = findMinimum(arr, 0, n - 1);

    cout << "Floor of " << key << " is: " << floor << endl;
    cout << "Ceiling of " << key << " is: " << ceil << endl;
    cout << "Peak element is: " << peak << endl;
    cout << "Minimum element is: " << minimum << endl;

    return 0;
}
