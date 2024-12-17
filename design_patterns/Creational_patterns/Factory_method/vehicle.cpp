#include "vehicle.h"

class Client {
private:
  Vehicle *vehicle;

public:
  Client(VehicleFactory *factory) { this->vehicle = factory->createVehicle(); }
  Vehicle *getVehicle() { return this->vehicle; }
};

int main() {
  VehicleFactory *factory = new TwoWheelerFactory();
  Client *client = new Client(factory);
  Vehicle *vehicle = client->getVehicle();

  vehicle->PrintVehicle();

  return 0;
}
