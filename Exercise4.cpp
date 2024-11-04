// Arda Barak
// 300129340
// Exercise 4

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Vehicle {                 //base class Vehicle
protected:
    string model;
public:
    Vehicle(const string& mdl) : model(mdl) {}
    virtual void showDetails() const = 0;
    string getModel() const { return model; }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {    //derived class Car
public:
    Car(const string& mdl) : Vehicle(mdl) {}
    void showDetails() const override {
        cout << "Car Model: " << model << endl; //printing model
    }
};

class Truck : public Vehicle {  //derived class Truck
    int loadCapacity;           //capacity of tons
public:
    Truck(const string& mdl, int capacity) : Vehicle(mdl), loadCapacity(capacity) {}
    void showDetails() const override {
        cout << "Truck Model:   " << model << ", Load Capacity:   " << loadCapacity << " tons" << endl; //printing result
    }
    int getLoadCapacity() const {
        return loadCapacity;
    }
};

template <typename T>           //class template Fleet<T>
class Fleet {
    vector<shared_ptr<T>> vehicles; //aggregation: storing vehicles in <vector>
public:
    void addVehicle(shared_ptr<T> vehicle) {    //add vehicle
        vehicles.push_back(vehicle);
    }
    void showDetails() const {
        for (const auto& vehicle : vehicles) {  //show details
            vehicle->showDetails();
        }
    }
    void removeVehicle(const string& model) {   //remove vehicle
        vehicles.erase(remove_if(vehicles.begin(), vehicles.end(), [&model](const shared_ptr<T>& vehicle) {return vehicle->getModel() == model;}), vehicles.end());
    }
};

template <>
class Fleet<Truck> {    //specialization for Fleet<Truck> to calc total load capacity
    vector<shared_ptr<Truck>> trucks;
public:
    void addVehicle(shared_ptr<Truck> truck)//addd vehicle
        {trucks.push_back(truck);}
    void showDetails() const {              //show details
        int totalLoadCapacity = 0;
        for (const auto& truck : trucks) {
            truck->showDetails();
            totalLoadCapacity += truck->getLoadCapacity();
        }
        cout << "Total Truck Load Capacity:   " << totalLoadCapacity << " tons" << endl;
    }
    void removeVehicle(const string& model) {//removing vehicle
        trucks.erase(remove_if(trucks.begin(), trucks.end(), [&model](const shared_ptr<Truck>& truck) {return truck->getModel() == model;}), trucks.end());
    }
};

int main() {    //main for interacting with the user and app
    Fleet<Car> carFleet;
    Fleet<Truck> truckFleet;
    int choice;
    do {    //mapping input to the functions
        cout << "\nChoose an option:    \n1. Add Car \n2. Add Truck \n3. Show Fleet Details \n4. Exit \n> ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string carModel;
            cout << "Enter Car Model:   ";
            getline(cin, carModel);
            carFleet.addVehicle(make_shared<Car>(carModel));
        }
        else if (choice == 2) {
            string truckModel;
            int loadCapacity;
            cout << "Enter Truck Model: ";
            getline(cin, truckModel);
            cout << "Enter Load Capacity (tons):   ";
            cin >> loadCapacity;
            cin.ignore();
            truckFleet.addVehicle(make_shared<Truck>(truckModel, loadCapacity));
        }
        else if (choice == 3) {
            cout << "\nCar Fleet Details:   \n";
            carFleet.showDetails();
            cout << "\nTruck Fleet Details: \n";
            truckFleet.showDetails();
        }
    } while (choice != 4);
    cout << "Exiting the program " << endl;
    return 0;
}
