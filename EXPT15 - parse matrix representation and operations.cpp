#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a non-zero element in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix in CSR format
struct SparseMatrixCSR {
    int rows;
    int cols;
    int numElements;
    vector<int> A; // Stores non-zero values
    vector<int> IA; // Stores row pointers
    vector<int> JA; // Stores column indices
};

// Function to initialize a sparse matrix in CSR format
SparseMatrixCSR initializeSparseMatrix(int rows, int cols, const vector<Element>& elements) {
    SparseMatrixCSR matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.numElements = elements.size();

    for (const Element& elem : elements) {
        matrix.A.push_back(elem.value);
        matrix.JA.push_back(elem.col);
    }

    int currentRow = -1;
    for (size_t i = 0; i < elements.size(); i++) {
        if (elements[i].row != currentRow) {
            matrix.IA.push_back(i);
            currentRow = elements[i].row;
        }
    }
    matrix.IA.push_back(elements.size());

    return matrix;
}

// Function to print the sparse matrix in CSR format
void printSparseMatrixCSR(const SparseMatrixCSR& matrix) {
    cout << "Rows: " << matrix.rows << " Columns: " << matrix.cols << endl;
    cout << "Number of non-zero elements: " << matrix.numElements << endl;

    cout << "A: ";
    for (int value : matrix.A) {
        cout << value << " ";
    }
    cout << endl;

    cout << "IA: ";
    for (int value : matrix.IA) {
        cout << value << " ";
    }
    cout << endl;

    cout << "JA: ";
    for (int value : matrix.JA) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<Element> elements = {
        {0, 1, 4},
        {0, 2, 7},
        {1, 0, 1},
        {2, 2, 5},
        {3, 1, 3},
    };

    SparseMatrixCSR matrix = initializeSparseMatrix(4, 3, elements);

    printSparseMatrixCSR(matrix);

    return 0;
}
