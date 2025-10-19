#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    float grade;
    int creditHours;

public:
    void inputCourse() {
        cout << "Enter grade (e.g., 4.0, 3.5 or etc ): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> creditHours;
    }

    float getGradePoints() const {
        return grade * creditHours;
    }

    int getCreditHours() const {
        return creditHours;
    }

    void displayCourse() const {
        cout << "Grade: " << grade << " | Credit Hours: " << creditHours << endl;
    }
};

class Student {
private:
    Course courses[10];
    int numCourses;

public:
    void inputCourses() {
        cout << "Enter number of courses: ";
        cin >> numCourses;

        for (int i = 0; i < numCourses; i++) {
            cout << "\nCourse " << i + 1 << ":\n";
            courses[i].inputCourse();
        }
    }

    float cgpa() const {
        float totalPoints = 0;
        int totalCredits = 0;

        for (int i = 0; i < numCourses; i++) {
            totalPoints += courses[i].getGradePoints();
            totalCredits += courses[i].getCreditHours();
        }

        if (totalCredits == 0) return 0;
        return totalPoints / totalCredits;
    }

    void displayResult() const {
        cout << "\n========== Course Details ==========\n";
        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << i + 1 << ": ";
            courses[i].displayCourse();
        }

        cout << "\nYour Final CGPA: " << cgpa() << endl;
    }
};

int main() {
    Student s;
    s.inputCourses();
    s.displayResult();
    return 0;
}
