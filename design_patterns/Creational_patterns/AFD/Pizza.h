#include <iostream>
// abstract product
class Pizza {
public:
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;
};

// concrete products
// Concrete New York Cheese Pizza
class NewYorkCheesePizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking New York-style cheese pizza." << std::endl;
  }

  void cut() override {
    std::cout << "Cutting New York-style cheese pizza." << std::endl;
  }

  void box() override {
    std::cout << "Boxing New York-style cheese pizza." << std::endl;
  }
};

// Concrete New York Pepperoni Pizza
class NewYorkPepperoniPizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking New York-style pepperoni pizza." << std::endl;
  }

  void cut() override {
    std::cout << "Cutting New York-style pepperoni pizza." << std::endl;
  }

  void box() override {
    std::cout << "Boxing New York-style pepperoni pizza." << std::endl;
  }
};

// Concrete Chicago Cheese Pizza
class ChicagoCheesePizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking Chicago-style cheese pizza." << std::endl;
  }

  void cut() override {
    std::cout << "Cutting Chicago-style cheese pizza." << std::endl;
  }

  void box() override {
    std::cout << "Boxing Chicago-style cheese pizza." << std::endl;
  }
};

// Concrete Chicago Pepperoni Pizza
class ChicagoPepperoniPizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking Chicago-style pepperoni pizza." << std::endl;
  }

  void cut() override {
    std::cout << "Cutting Chicago-style pepperoni pizza." << std::endl;
  }

  void box() override {
    std::cout << "Boxing Chicago-style pepperoni pizza." << std::endl;
  }
};
