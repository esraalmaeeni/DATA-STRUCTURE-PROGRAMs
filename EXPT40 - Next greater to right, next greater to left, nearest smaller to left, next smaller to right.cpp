#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to find the next greater element to the right (NGR)
vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> ngr(n, -1); // Initialize with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ngr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ngr;
}

// Function to find the next greater element to the left (NGL)
vector<int> nextGreaterLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> ngl(n, -1); // Initialize with -1
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ngl[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ngl;
}

// Function to find the nearest smaller element to the left (NSL)
vector<int> nearestSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> nsl(n, -1); // Initialize with -1
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            nsl[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return nsl;
}

// Function to find the next smaller element to the right (NSR)
vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> nsr(n, -1); // Initialize with -1
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            nsr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return nsr;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    
    vector<int> ngr = nextGreaterRight(arr);
    vector<int> ngl = nextGreaterLeft(arr);
    vector<int> nsl = nearestSmallerLeft(arr);
    vector<int> nsr = nextSmallerRight(arr);

    cout << "Next Greater to Right: ";
    for (int num : ngr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Greater to Left: ";
    for (int num : ngl) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Nearest Smaller to Left: ";
    for (int num : nsl) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Next Smaller to Right: ";
    for (int num : nsr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
