#include <iostream>
using namespace std;

// VehicleTemplate ):

// Responsibility: Defines the overall algorithm structure for building a vehicle.
// It includes a template method (“buildVehicle”) that orchestrates the steps of
// vehicle construction

class VehicleTemplate
{
public:
    void buildVehicle()
    {
        assembleBody();
        installEngine();
        addWheels();
        ready();
    }
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
    virtual void ready() = 0;
};

class Car : public VehicleTemplate
{
public:
    void assembleBody() override
    {
        cout << "Car body assembled" << endl;
    }
    void installEngine() override
    {
        cout << "Car engine installed " << endl;
    }
    void addWheels() override
    {
        cout << "Car wheels are added" << endl;
    }
    void ready() override
    {
        cout << "Car is ready " << endl;
    }
};

class MoterCycle : public VehicleTemplate
{
public:
    void assembleBody() override
    {
        cout << "MoterCycle body assembled" << endl;
    }
    void installEngine() override
    {
        cout << "MoterCycle engine installed " << endl;
    }
    void addWheels() override
    {
        cout << "MoterCycle wheels are added" << endl;
    }
    void ready() override
    {
        cout << "MoterCycle is ready " << endl;
    }
};
