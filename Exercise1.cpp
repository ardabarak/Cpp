// Arda Barak
// 300129340
// Exercise 1

#include <iostream>
#include <queue>
#include <string>

struct Patient {
    std::string name;
    int severity;
    int order_of_arrival;
    Patient(const std::string& num, int se, int ordarva) : name(num), severity(se), order_of_arrival(ordarva) {}
};

bool operator<(const Patient& p1, const Patient& p2) {
    if (p1.severity == p2.severity) {return p1.order_of_arrival > p2.order_of_arrival;} //firsts served first
    return p1.severity < p2.severity; //greater served first
}


int main() {
    std::priority_queue<Patient> patients;
    bool exit_program = false;
    int choice = 0;
    int arrival_counter = 0;

    while (!exit_program) {
        std::cout << "1. Add Patient\n2. Serve Patient\n3. Exit\n";
        std::cout << "Enter your choice : ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int severity;
                std::cout << "Enter patient's name  : ";
                std::cin >> name;
                std::cout << "Enter patient's condition severity (1-10, with 10 being most severe)  : ";
                std::cin >> severity;
                arrival_counter++;
                patients.emplace(name, severity, arrival_counter);
                std::cout << "Patient added : " << name << " with severity  : " << severity << std::endl;
                break;}
            case 2: {
                if (patients.empty()) {std::cout << "no patients to be served" << std::endl;} 
                else {
                    while (!patients.empty()) {
                        const Patient& current_patient = patients.top();
                        std::cout << "Serving   : " << current_patient.name << " with severity  : " << current_patient.severity << std::endl;
                        patients.pop();}
                    }
                break;}
            case 3: {
                exit_program = true;
                break;}
            default: std::cout << "invalid choice, please try again " << std::endl;
        }
    }
    return 0;
}
