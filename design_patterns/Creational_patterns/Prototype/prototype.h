#include <iostream>

// abstract prototype
class Shape {
public:
  virtual Shape *clone() const = 0;
  virtual void Draw() const = 0;
  virtual ~Shape() {}
};

// concrete prototype
class Circle : public Shape {
public:
  Circle(double r) : radius(r) {}
  Shape *clone() const override {
    return new Circle(*this);
  } // copy constructor
  void Draw() const override { std::cout << "Drawing a circle" << std::endl; }

private:
  double radius;
};

// concrete prototype
class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}
  Shape *clone() const override { return new Rectangle(*this); }
  void Draw() const override {
    std::cout << "Drawing a rectangle of width : " << this->width
              << " and height : " << this->height << std::endl;
  }
};
