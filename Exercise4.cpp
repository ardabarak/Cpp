// Arda Barak
// 300129340
// Exercise 4

#include <iostream>
#include <map>
#include <memory>
#include <string>

class Sensor {  //base class
public:
    virtual ~Sensor() = default;

    virtual void handleEvent() const = 0; //virtual function

    static void handleSensorEvent(const Sensor* sensor) {sensor->handleEvent();} //static method for event handling
};

class TemperatureSensor : public Sensor {  //derived class for TemperatureSensor
public:
    void handleEvent() const override {
        std::cout << "Handling temperature sensor event.\n";
    }
};

class PressureSensor : public Sensor {    //derived class for PressureSensor
public:
    void handleEvent() const override {
        std::cout << "Handling pressure sensor event.\n";
    }
};

int main() {
    //creating sensors
    std::unique_ptr<Sensor> tempSensor1 = std::make_unique<TemperatureSensor>();
    std::unique_ptr<Sensor> pressureSensor1 = std::make_unique<PressureSensor>();
    //mapping sensor ids to pointers
    std::map<std::string, void(*)(const Sensor*)> sensorMap;
    sensorMap["TEMP SENSOR 1"] = &Sensor::handleSensorEvent;
    sensorMap["PRESSURE SENSOR 1"] = &Sensor::handleSensorEvent;
    //mapping sensor ids to objects
    std::map<std::string, Sensor*> sensorObjects;
    sensorObjects["TEMP SENSOR 1"] = tempSensor1.get();
    sensorObjects["PRESSURE SENSOR 1"] = pressureSensor1.get();
    std::cout << "Simulating events:\n";
    for (const auto& entry : sensorMap) {
        std::cout << "Event from " << entry.first << ": ";
        entry.second(sensorObjects[entry.first]);
    }
    return 0;
}
