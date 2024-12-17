#include <iostream>
#include <list>
using namespace std;

// ------------------------- Reciever -------------------------
class Light
{
private:
    bool SwitchOn;

public:
    Light(bool state = false) : SwitchOn(state) {}
    bool isSwitchOn() const { return this->SwitchOn; }
    void toggleSwitch()
    {
        this->SwitchOn = !this->SwitchOn;
        this->SwitchOn ? cout << "light on" << endl : cout << "light off" << endl;
    }
    void toggleSwitch(bool state) { this->SwitchOn = state; }
};

// ------------------------- Reciever -------------------------
class Lock
{
private:
    bool Locked;

public:
    Lock(bool state = false) : Locked(state) {}

    bool isLocked() const { return this->Locked; }
    void LockUnlock() { this->Locked = !this->Locked; }
    void LockUnlock(bool state) { this->Locked = state; }
};

// ------------------------- Commnad -------------------------
class Command
{
public:
    virtual void execute() = 0;
};

// ------------------------- Concrete Command -------------------------
class SwitchLightCommand : public Command
{
private:
    Light *light;

public:
    SwitchLightCommand() { this->light = new Light(); }
    SwitchLightCommand(Light *ligth) : light(light) {}
    void execute() override { this->light->toggleSwitch(); }
    const Light *getLight() const { return this->light; }
};
// ------------------------- Concrete Command -------------------------
class LockUnlockCommand : public Command
{
private:
    Lock *lock;

public:
    LockUnlockCommand() { this->lock = new Lock(); }
    LockUnlockCommand(Lock *lock) { this->lock = lock; }
    void execute() override { this->lock->LockUnlock(); }
    const Lock *getLock() const { return this->lock; }
};

// ------------------------- Invoker -------------------------
class Room
{
private:
    double width, height;
    Command *command;

public:
    void setCommand(Command *command) { this->command = command; }
    void executeCommand() { this->command->execute(); }
};

// ------------------------- EXTRAS -------------------------
class Furniture
{
};

class LivingRoom : public Room
{
private:
    Furniture *furniture;
};

class BathRoom : public Room
{
};

class BedRoom1 : public Room
{
};

class Kitchen : public Room
{
};

// ------------------------- Client -------------------------
class House
{
private:
    list<Room *> rooms;

public:
    void addRoom(Room *room)
    {
        this->rooms.push_back(room);
    }
    list<Room *> getRooms() const { return this->rooms; }
};