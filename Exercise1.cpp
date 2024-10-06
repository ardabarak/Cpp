// Arda Barak
// 300129340

#include <iostream>
using namespace std;


// A: course class
class Course
{
private:
    int courseCode;
    int courseHours;
public:
    Course(int code, int hours) : courseCode(code), courseHours(hours) {} //constructor

    int getNum() const   {return courseCode;}  //getter for coursecode

    int getHours() const  {return courseHours;} //getter for coursehours

};


// B: student class
class Student
{
private:
    int studentID;
    int maxCourses;
    int numCourses;
    Course** courseList;
    int* grades;

public:
    Student(int idNo, int maxCo) : studentID(idNo), maxCourses(maxCo), numCourses(0) { //constructor
        courseList = new Course*[maxCourses];
        grades = new int[maxCourses];
    }

    ~Student() { //destructor
        delete[] courseList;
        delete[] grades;
    }

    int average() const { //calc average
        int sum =0;
        for (int i = 0; i < numCourses; i++) {
            sum += grades[i];
        }
        return (numCourses > 0) ? ((int) sum/numCourses) : (0);
    }

    int totalHours() const { //calc total hours
        int total = 0;
        for (int i = 0; i < numCourses; i++) {
            total += courseList[i]->getHours();
        } return total;
    }

    void addCourse(Course* course, int grade) { //adding a course
        if (numCourses < maxCourses) {
            courseList[numCourses] = course;
            grades[numCourses] = grade;
            numCourses++;
        } else {
            cout << " - Max number of courses enrolled - " << endl;
        }
    }

};
int main() {
    Course courseA(1234, 3);
    Course courseB(4321, 6);
    Student student(300123456, 5);
    student.addCourse(&courseA, 85); //course & grades
    student.addCourse(&courseB, 95);
    cout << "Average:       " << student.average() << endl; //calc and show students average and total hours
    cout << "Total Hours:   " << student.totalHours() << endl;
    return 0;
}
