#include "decorator.h"

int main() {
  // plain IceCream
  IceCream *vanillaIceCream = new VanillaIceCream();
  std::cout << vanillaIceCream->getDescription() << std::endl;
  std::cout << vanillaIceCream->cost() << std::endl;

  // chocalate Decorator
  IceCream *vanillaChocalateIceCream = new ChocalateDecorator(vanillaIceCream);
  std::cout << vanillaChocalateIceCream->getDescription() << " costs "
            << vanillaChocalateIceCream->cost() << std::endl;

  // Caramel Decorator
  IceCream *vanillaCaramelIceCream = new CaramelDecorator(vanillaIceCream);
  std::cout << vanillaCaramelIceCream->getDescription() << " costs "
            << vanillaCaramelIceCream->cost() << std::endl;

  return 0;
}
