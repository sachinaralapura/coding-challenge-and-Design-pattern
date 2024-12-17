#include <iostream>
#include <list>
using namespace std;

// ------------------------- colleague Interface -------------------------
class Airplane
{
public:
    virtual void requestTakeOff() = 0;
    virtual void requestLanding() = 0;
    virtual void notify(string message) = 0;
    virtual string getName() const = 0;
};

// -------------------------Abstract  Mediator( Interface) -------------------------

class ControlTower
{
public:
    virtual void requestTakeOff(Airplane *) = 0;
    virtual void requestLanding(Airplane *) = 0;
    virtual void addPlane(Airplane *plane) = 0;
    virtual void notifyAll(string, Airplane *) = 0;
};

// ------------------------- concrete Mediator -------------------------

class AirTrafficControlTower : public ControlTower
{
private:
    list<Airplane *> *airplaneList;

public:
    AirTrafficControlTower()
    {
        this->airplaneList = new list<Airplane *>;
    }

    void addPlane(Airplane *plane) override
    {
        this->airplaneList->push_back(plane);
    }

    void requestTakeOff(Airplane *plane) override
    {
        cout << plane->getName() << " : Requesting for taking off" << endl;
        notifyAll(plane->getName() + " Requesting for taking off", plane);
    }
    void requestLanding(Airplane *plane) override
    {
        cout << plane->getName() << " : Requesting for landing" << endl;
        notifyAll(plane->getName() + " Requesting for landing", plane);
    }

    void notifyAll(string message, Airplane *current) override
    {
        for (auto plane : *this->airplaneList)
        {
            if (current != plane)
                plane->notify(message);
        }
    }
};

// ------------------------- concrete Colleague -------------------------

class CommercialPlane : public Airplane
{
private:
    string name;
    ControlTower *mediator;

public:
    CommercialPlane(string name, ControlTower *mediator)
    {
        this->name = name;
        this->mediator = mediator;
        this->mediator->addPlane(this);
    };
    string getName() const { return this->name; }
    void requestTakeOff()
    {
        this->mediator->requestTakeOff(this);
    }
    void requestLanding()
    {
        this->mediator->requestLanding(this);
    }
    void notify(string message)
    {
        cout << this->getName() << " recieved :  " << message << endl;
    }
};

int main(int argc, char const *argv[])
{
    ControlTower *airTrafficControlTower = new AirTrafficControlTower();

    Airplane *plane1 = new CommercialPlane("Plane 1", airTrafficControlTower);
    Airplane *plane2 = new CommercialPlane("Plane 2", airTrafficControlTower);
    Airplane *plane3 = new CommercialPlane("Plane 3", airTrafficControlTower);
    Airplane *plane4 = new CommercialPlane("Plane 4", airTrafficControlTower);

    plane1->requestLanding();
    plane1->requestTakeOff();
    plane1->notify("Terrorist attack");
    return 0;
}
