#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to hold course information
struct Course {
    string name;
    double grade;       // Grade points (e.g., 10 for A+, 9 for A, etc.)
    int creditHours;
};

// Function to calculate GPA
double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const Course& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCredits += course.creditHours;
    }

    if (totalCredits == 0) return 0.0;
    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;
    vector<Course> semesterCourses;
    vector<double> semesterGPAs;

    cout << "Enter the number of semesters: ";
    int numSemesters;
    cin >> numSemesters;

    for (int sem = 1; sem <= numSemesters; ++sem) {
        cout << "\n--- Semester " << sem << " ---\n";
        cout << "Enter number of courses: ";
        cin >> numCourses;

        vector<Course> currentSemester;

        for (int i = 0; i < numCourses; ++i) {
            Course c;
            cout << "Course " << i + 1 << " name: ";
            cin >> ws; // consume newline
            getline(cin, c.name);
            cout << "Enter grade points (e.g., 10 for A+): ";
            cin >> c.grade;
            cout << "Enter credit hours: ";
            cin >> c.creditHours;
            currentSemester.push_back(c);
        }

        double gpa = calculateGPA(currentSemester);
        semesterGPAs.push_back(gpa);

        // Display semester GPA
        cout << fixed << setprecision(2);
        cout << "\nCourses for Semester " << sem << ":\n";
        for (const Course& c : currentSemester) {
            cout << "Course: " << c.name << ", Grade: " << c.grade << ", Credit: " << c.creditHours << endl;
        }
        cout << "GPA for Semester " << sem << ": " << gpa << endl;
    }

    // Compute overall CGPA
    double totalGPA = 0;
    for (double g : semesterGPAs) {
        totalGPA += g;
    }
    double cgpa = totalGPA / semesterGPAs.size();

    cout << "\n=================================\n";
    cout << "Your Overall CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "=================================\n";

    return 0;
}
