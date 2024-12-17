#include "Pizza.h"

// abstract Pizza Factory
class PizzaFactory
{
public:
  virtual Pizza *createCheesePizza() = 0;
  virtual Pizza *createPepperoniPizza() = 0;
};

// concreate New York Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory
{
public:
  Pizza *createCheesePizza() { return new NewYorkCheesePizza(); }
  Pizza *createPepperoniPizza() { return new NewYorkPepperoniPizza(); }
};

// concrete Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory
{
public:
  Pizza *createCheesePizza() { return new ChicagoCheesePizza(); }
  Pizza *createPepperoniPizza() { return new ChicagoPepperoniPizza(); }
};

int main()
{

  PizzaFactory *pizzaFactory = new ChicagoPizzaFactory();
  Pizza *cheesePizza = pizzaFactory->createCheesePizza();
  Pizza *pepperoniPizza = pizzaFactory->createPepperoniPizza();

  cheesePizza->bake();
  cheesePizza->cut();
  cheesePizza->box();

  pepperoniPizza->bake();
  pepperoniPizza->cut();
  pepperoniPizza->box();

  return 0;
}
