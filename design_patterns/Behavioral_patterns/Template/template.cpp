#include "template.h"

int main(int argc, char const *argv[])
{
    VehicleTemplate *temp = new Car();
    temp->buildVehicle();
    temp = new MoterCycle();
    temp->buildVehicle();
    return 0;
}
