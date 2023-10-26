#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int numStudents = 5;    // Number of students
    const int numSubjects = 5;    // Number of subjects

    int marks[numStudents][numSubjects];

    // Input marks for each student in each subject
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter marks for Student " << i + 1 << " in 5 subjects: ";
        for (int j = 0; j < numSubjects; j++) {
            cin >> marks[i][j];
        }
    }

    // Calculate and display the total marks for each student
    cout << "\nTotal marks for each student:" << endl;
    for (int i = 0; i < numStudents; i++) {
        int total = 0;
        for (int j = 0; j < numSubjects; j++) {
            total += marks[i][j];
        }
        cout << "Student " << i + 1 << ": " << total << endl;
    }

    // Calculate and display the average marks for each subject
    cout << "\nAverage marks for each subject:" << endl;
    for (int j = 0; j < numSubjects; j++) {
        int subjectTotal = 0;
        for (int i = 0; i < numStudents; i++) {
            subjectTotal += marks[i][j];
        }
        double subjectAverage = static_cast<double>(subjectTotal) / numStudents;
        cout << "Subject " << j + 1 << ": " << fixed << setprecision(2) << subjectAverage << endl;
    }

    return 0;
}
