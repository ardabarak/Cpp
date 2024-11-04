// Arda Barak
// 300129340
// Exercise 1

#include <iostream>
#include <string>
using namespace std;

class Employee {                    //base class
protected:
    string name;
public:
    Employee(string empName) : name(empName) {}
    virtual void calculateBonus() = 0;
};

class Manager : public Employee {   //derived Manager class
    int projectsManaged;
public:
    Manager(string empName, int projects) : Employee(empName), projectsManaged(projects) {}

    void calculateBonus() override {
        int bonus = projectsManaged * 500;
        cout << "Manager:   " << name << " has a bonus of:  $" << bonus << endl;
    }
};

class Developer : public Employee { //derived Developer class
    int linesOfCode;
public:
    Developer(string empName, int lines) : Employee(empName), linesOfCode(lines) {}

    void calculateBonus() override {
        int bonus = linesOfCode * 0.05;
        cout << "Developer: " << name << " has a bonus of:  $" << bonus << endl;
    }
};

int main() {
    string managerName, developerName;
    int projects, lines;
    cout << "Enter Manager's Name:  ";       //manager input
    cin >> managerName;
    cout << "Enter number of projects managed:  ";
    cin >> projects;
    Manager manager(managerName, projects);
    cout << "\nEnter Developer's Name:  ";   //developer input
    cin >> developerName;
    cout << "Enter number of lines of code written: ";
    cin >> lines;
    Developer developer(developerName, lines);
    manager.calculateBonus();               //calculating and showing results
    developer.calculateBonus();
    return 0;
}
