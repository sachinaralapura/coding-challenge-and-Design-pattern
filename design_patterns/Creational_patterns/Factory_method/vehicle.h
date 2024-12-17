#include <iostream>
#include <string>

// abstract product
class Vehicle {
protected:
  std::string vehicle_type;

public:
  virtual void PrintVehicle() = 0;
};

// concrete products
class TwoWheeler : public Vehicle {
public:
  TwoWheeler() { this->vehicle_type = "Two wheeler"; }
  void PrintVehicle() override { std::cout << this->vehicle_type << std::endl; }
};

class FourWheeler : public Vehicle {
public:
  FourWheeler() { this->vehicle_type = "Four Wheeeler"; }
  void PrintVehicle() override { std::cout << this->vehicle_type << std::endl; }
};

// abstract factory or abstract creator
class VehicleFactory {
public:
  virtual Vehicle *createVehicle() = 0;
};

// concrete factory or concrete creator
class TwoWheelerFactory : public VehicleFactory {
public:
  Vehicle *createVehicle() override { return new TwoWheeler(); }
};

class FourWheelerFactory : public VehicleFactory {
public:
  Vehicle *createVehicle() override { return new FourWheeler(); }
};
