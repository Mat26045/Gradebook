#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;


char calculate_grade(double average_score) {
    if (average_score >= 90) {
        return 'A';
    }
    else if (average_score >= 80) {
        return 'B';
    }
    else if (average_score >= 70) {
        return 'C';
    }
    else if (average_score >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

int main() {
    string student_names[5];
    char student_grades[5];
    double student_scores[5][4]; 

    for (int i = 0; i < 5; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        getline(cin, student_names[i]);

        for (int j = 0; j < 4; j++) {  
            while (true) {
                cout << "Enter score " << j + 1 << " for " << student_names[i] << " (0-100): ";
                cin >> student_scores[i][j];

                if (student_scores[i][j] < 0 || student_scores[i][j] > 100) {
                    cout << "Invalid input. Score must be between 0 and 100." << endl;
                }
                else {
                    break; 
                }
            }
        }
        cin.ignore();  
    }

      for (int i = 0; i < 5; i++) {
        sort(student_scores[i], student_scores[i] + 4);

        double total = 0;
        for (int j = 1; j < 4; j++) {  
            total += student_scores[i][j];
        }

        double average_score = total / 3.0;  
        student_grades[i] = calculate_grade(average_score);  

        cout << "\n" << student_names[i] << "'s average score (dropping lowest): "
            << average_score << endl;
        cout << student_names[i] << "'s grade: " << student_grades[i] << endl;
    }

    return 0;
}
