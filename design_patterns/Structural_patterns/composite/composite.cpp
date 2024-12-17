// component
#include <iostream>
#include <vector>
enum SHAPE { CIRCLE, TRIANGLE, RECTANGLE, DRAWING };
class Shape {
public:
  virtual void draw() const = 0;
};

// leaf
class Circle : public Shape {
public:
  void draw() const override { std::cout << "Drawing circle" << std::endl; }
};

// leaf
class Triangle : public Shape {
public:
  void draw() const override { std::cout << "Drawing Triangle" << std::endl; }
};

// leaf
class Rectangle : public Shape {
public:
  void draw() const override { std::cout << "Drawing Rectangle" << std::endl; }
};

// composite
class Drawing : public Shape {
private:
  std::vector<Shape *> shapes;

public:
  void addShapes(Shape *shape);
  void addShapes(SHAPE shape);
  void draw() const override;
  Shape *createShape(SHAPE);
};

void Drawing::addShapes(Shape *shape) { shapes.push_back(shape); }
void Drawing::addShapes(SHAPE shape) { shapes.push_back(createShape(shape)); }
void Drawing::draw() const {
  for (const Shape *shape : this->shapes) {
    shape->draw();
  }
}

Shape *Drawing::createShape(SHAPE shape) {
  Shape *newShape;
  if (shape == SHAPE::CIRCLE)
    newShape = new Circle();
  else if (shape == SHAPE::TRIANGLE)
    newShape = new Triangle();
  else if (shape == SHAPE::RECTANGLE)
    newShape = new Rectangle();
  else {
    std::cout << "Invalid shape" << std::endl;
    newShape = nullptr;
  }
  return newShape;
}

int main() {
  Drawing toplevel;
  toplevel.addShapes(SHAPE::CIRCLE);
  toplevel.addShapes(SHAPE::RECTANGLE);
  toplevel.addShapes(SHAPE::TRIANGLE);

  Drawing nested;
  nested.addShapes(SHAPE::CIRCLE);
  nested.addShapes(SHAPE::RECTANGLE);
  nested.addShapes(SHAPE::TRIANGLE);

  toplevel.addShapes(&nested);
  toplevel.draw();
  return 0;
}
