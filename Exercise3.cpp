// Arda Barak
// 300129340
// Exercise 3

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

class Employee {
    int id;
    std::string name;
    std::string department;

public:
    Employee() : id(0), name(""), department("") {}

    Employee(int id, const std::string& name, const std::string& department)
        : id(id), name(name), department(department) {}

    std::string toString() const { //to str
        std::ostringstream oss;
        oss << id << ", " << name << ", " << department;
        return oss.str();
    }

    static Employee fromString(const std::string& str) { //from str
        std::istringstream iss(str);
        std::string token;
        int id;
        std::string name, department;

        std::getline(iss, token, ',');
        id = std::stoi(token);
        std::getline(iss, name, ',');
        std::getline(iss, department, ',');

        return Employee(id, name, department);
    }

    friend void updateEmployeeDep(Employee& employee, const std::string& newDepartment);
    friend Employee* findEmployeeByID(std::vector<Employee>& employees, int id);
};

void updateEmployeeDep(Employee& employee, const std::string& newDepartment) { //update employees department
    employee.department = newDepartment;
    std::cout << "Department updated successfully." << std::endl;
}

void readEmployeesFromFile(const std::string& filename, std::vector<Employee>& employees) { //read employees from txt
    std::ifstream file(filename);
    if (!file.is_open()) {throw std::runtime_error("Cannot open file.");}

    std::string line;
    while (std::getline(file, line)) {
        employees.push_back(Employee::fromString(line));
    }
    file.close();
}

void writeEmployeesToFile(const std::string& filename, const std::vector<Employee>& employees) { //write emploee to txt
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }

    for (const auto& employee : employees) {
        file << employee.toString() << std::endl;
    }

    file.close();
}

Employee* findEmployeeByID(std::vector<Employee>& employees, int id) { //find employee by id
    for (auto& employee : employees) {
        if (employee.id == id) {return &employee;}
    }
    return nullptr;
}

int main() {
    std::vector<Employee> employees;

    try {
        readEmployeesFromFile("employees.txt", employees);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    int searchID;
    std::cout << "Enter ID to search: ";
    std::cin >> searchID;
    Employee* employee = findEmployeeByID(employees, searchID);

    if (employee) {
        std::cout << "Found employee: " << employee->toString() << std::endl;
        std::string newDepartment;
        std::cout << "Enter new department for the employee: ";
        std::cin >> newDepartment;
        updateEmployeeDep(*employee, newDepartment);
        std::cout << "Updated employee: " << employee->toString() << std::endl;
    } 
    else {std::cout << "Employee with ID " << searchID << " not found." << std::endl;}

    try {
        writeEmployeesToFile("employees.txt", employees);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
