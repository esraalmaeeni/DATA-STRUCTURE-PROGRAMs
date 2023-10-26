#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Function to find the first negative integer in every window of size k
vector<int> findFirstNegativeInWindow(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> negIndices;

    int n = arr.size();
    int i;

    // Process the first window of size k
    for (i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    // Continue processing the rest of the windows
    for (; i < n; i++) {
        // Add the first negative element from the previous window (if any)
        if (!negIndices.empty()) {
            result.push_back(arr[negIndices.front()]);
        } else {
            result.push_back(0); // No negative element in the window
        }

        // Remove elements from the front that are not in the current window
        while (!negIndices.empty() && negIndices.front() <= i - k) {
            negIndices.pop_front();
        }

        // Add the current element to the deque if it's negative
        if (arr[i] < 0) {
            negIndices.push_back(i);
        }
    }

    // Process the last window
    if (!negIndices.empty()) {
        result.push_back(arr[negIndices.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = findFirstNegativeInWindow(arr, k);

    cout << "First negative integers in every window of size " << k << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
