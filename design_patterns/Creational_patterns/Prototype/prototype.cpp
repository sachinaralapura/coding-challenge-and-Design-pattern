#include "prototype.h"
int main() {
  Shape *circlePrototype = new Circle(10.0);
  Shape *rectanglePrototype = new Rectangle(5.0, 5.0);
  Shape *circle1 = circlePrototype->clone();
  Shape *rectangle1 = rectanglePrototype->clone();

  circle1->Draw();
  rectangle1->Draw();

  return 0;
}
