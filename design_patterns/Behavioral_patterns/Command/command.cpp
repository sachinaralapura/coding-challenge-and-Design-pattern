#include "command.h"

int main(int argc, char const *argv[])
{
    House newHouse;

    Room *livingRoom = new LivingRoom();
    Command *lightCommand = new SwitchLightCommand();
    livingRoom->setCommand(lightCommand);

    livingRoom->executeCommand();
    livingRoom->executeCommand();
    livingRoom->executeCommand();
    livingRoom->executeCommand();
    livingRoom->executeCommand();
    livingRoom->executeCommand();

    newHouse.addRoom(livingRoom);

    return 0;
}
