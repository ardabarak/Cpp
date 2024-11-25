// Arda Barak
// 300129340
// Exercise 4

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <memory>
using namespace std;

class Student {
public:
    string studentID;
    map<string, int> subjects;
    explicit Student(const string& id) : studentID(id) {}
    void updateScore(const string& subject, int score) {subjects[subject] = score;}

    int getScore(const string& subject) const {//getting score
        auto it = subjects.find(subject);
        return it != subjects.end() ? it->second : -1;
    }

    void display() const {//showing
        cout << "Student ID: " << studentID << endl;
        if (subjects.empty()) {cout << "  No subjects recorded yet" << endl;} 
        else {
            for (const auto& subject : subjects) 
                {cout << "  " << subject.first << " : " << subject.second << endl;}
            }
    }
};

class StudentManager {
private:
    set<shared_ptr<Student>> students;
    shared_ptr<Student> findStudent(const string& studentID) const {
        for (const auto& student : students) {
            if (student->studentID == studentID) {return student;}
        }
        return nullptr;
    }

public:
    void addStudent(const string& studentID) {//adding stdents
        if (findStudent(studentID)) {
            cout << "Student with ID    " << studentID << " already exists" << endl;
            return;}
        students.insert(make_shared<Student>(studentID));
        cout << "Student with ID    " << studentID << " added successfully" << endl;
    }

    void updateStudentScore(const string& studentID, const string& subject, int score) {//updating grades
        auto student = findStudent(studentID);
        if (student) {
            student->updateScore(subject, score);
            cout   << "Score for subject    '" << subject << "' updated to  " << score << endl;} 
        else {cout << "Student with ID      " << studentID << " not found   " << endl;}
    }

    void displayStudentRecord(const string& studentID) const {//showing student record
        auto student = findStudent(studentID);
        if (student) {student->display();} 
        else {cout << "Student with ID " << studentID << " not found." << endl;}
    }
};

int main() {
    StudentManager manager;
    bool exit = false;
    while (!exit) {
        cout << "\n1. Add Student\n2. Update Student Score\n3. Display Student Record\n4. Exit\n";
        cout << "Enter your choice  : ";
        int choice;
        cin >> choice;
        string studentID, subject;
        int score;
        switch (choice) {
            case 1: {
                cout << "Enter student ID   : ";
                cin >> studentID;
                manager.addStudent(studentID);
                break;}
            case 2: {
                cout << "Enter student ID   : ";
                cin >> studentID;
                cout << "Enter subject name : ";
                cin >> subject;
                cout << "Enter score    : ";
                cin >> score;
                manager.updateStudentScore(studentID, subject, score);
                break;}
            case 3: {
                cout << "Enter student ID   : ";
                cin >> studentID;
                manager.displayStudentRecord(studentID);
                break;}
            case 4: {exit = true;   break;}
            default:{cout << "Invalid choice please try again" << endl;}
        }
    }
    return 0;
}
