// component
#include <iostream>
#include <string>
class IceCream {
public:
  virtual std::string getDescription() const = 0;
  virtual double cost() const = 0;
};

// concreate component
class VanillaIceCream : public IceCream {

public:
  std::string getDescription() const override { return "Vanilla Ice Cream"; }

  double cost() const override { return 160.0; }
};

// concreate component
class MintIceCream : public IceCream {
public:
  std::string getDescription() const override { return "Mint Ice Cream"; }

  double cost() const override { return 200; }
};

// decorator interface
class IceCreamDecorator : public IceCream {
protected:
  IceCream *iceCream;

public:
  IceCreamDecorator(IceCream *ice) { this->iceCream = ice; };

  std::string getDescription() const override {
    return this->iceCream->getDescription();
  }

  double cost() const override { return this->iceCream->cost(); }
};

// concreate Decorator
class ChocalateDecorator : public IceCreamDecorator {
public:
  ChocalateDecorator(IceCream *ice) : IceCreamDecorator(ice){};

  std::string getDescription() const override {
    return this->iceCream->getDescription() + " with Chocalate";
  }

  double cost() const override { return this->iceCream->cost() + 30.0; }
};

// concreate Decorator
class CaramelDecorator : public IceCreamDecorator {
public:
  CaramelDecorator(IceCream *ice) : IceCreamDecorator(ice){};

  std::string getDescription() const override {
    return this->iceCream->getDescription() + " with Caramel";
  }

  double cost() const override { return this->iceCream->cost() + 40.0; }
};
