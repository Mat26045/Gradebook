#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 4;

double calculateAverage(double scores[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / size;
}

char assignGrade(double averageScore) {
    if (averageScore >= 90) {
        return 'A';
    }
    else if (averageScore >= 80) {
        return 'B';
    }
    else if (averageScore >= 70) {
        return 'C';
    }
    else if (averageScore >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

int main() {
    string studentNames[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];
    char letterGrades[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter details for student " << (i + 1) << ":\n";

        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, studentNames[i]);

        for (int j = 0; j < NUM_TESTS; j++) {
            cout << "Enter test score " << (j + 1) << ": ";
            cin >> testScores[i][j];
        }

        double averageScore = calculateAverage(testScores[i], NUM_TESTS);

        letterGrades[i] = assignGrade(averageScore);

        cin.ignore();
    }

    cout << "\nStudent Performance:\n";
    cout << left << setw(20) << "Student Name" << setw(15) << "Average Score" << "Grade\n";

    for (int i = 0; i < NUM_STUDENTS; i++) {
        double averageScore = calculateAverage(testScores[i], NUM_TESTS);
        cout << left << setw(20) << studentNames[i]
            << setw(15) << fixed << setprecision(2) << averageScore
            << letterGrades[i] << endl;
    }

    return 0;
}
