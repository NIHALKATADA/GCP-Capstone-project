#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << "=== 1D Array: Single Student Marks ===\n";
    int numSubjects1D = 5;
    int marks1D[5];
    for (int i = 0; i < numSubjects1D; i++) {
        cout << "Enter marks for Subject " << i + 1 << ": ";
        cin >> marks1D[i];
    }
    cout << "\nDisplaying Single Student Marks:\n";
    for (int i = 0; i < numSubjects1D; i++) {
        cout << "Subject " << i + 1 << ": " << marks1D[i] << "\n";
    } 
    cout << "\n--------------------------------------\n\n";
    cout << "=== 2D Array: Multiple Students Marks ===\n";
    int numStudents = 3;
    int numSubjects2D = 4;
    int marks2D[3][4]; 
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter marks for Student " << i + 1 << ":\n";
        for (int j = 0; j < numSubjects2D; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks2D[i][j];
        }
    }
    cout << "\nDisplaying Marks for All Students:\n";
    cout << "          Sub1  Sub2  Sub3  Sub4\n"; 
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < numSubjects2D; j++) {
            cout << setw(4) << marks2D[i][j] << "  "; 
        }
        cout << "\n";
    }
    return 0;
}