#include <iostream>
#include <string>
enum Type { Raster, Vector };
// Implementation
class Renderer {
public:
  virtual void render() = 0;
  virtual ~Renderer(){};
};


class VectorRenderer : public Renderer {
public:
  void render() override { std::cout << "Rendering as a vector" << std::endl; }
};

class RasterRenderer : public Renderer {
public:
  void render() override { std::cout << "Rendering as a raster" << std::endl; }
};

// abstraction : Shape
class Shape {
protected:
  Renderer *renderer;

public:
  virtual void draw() = 0;
  virtual void ChangeRenderer(Type type) {
    if (type == Type::Raster) {
      delete renderer;
      renderer = new RasterRenderer();
    } else if (type == Type::Vector) {
      delete renderer;
      renderer = new VectorRenderer();
    }
  }
};

// Concrete Abstractions:
class Circle : public Shape {
public:
  Circle(){};
  Circle(Type type) {
    if (type == Type::Raster)
      this->renderer = new RasterRenderer();
    else if (type == Type::Vector)
      this->renderer = new VectorRenderer();
    else {
      std::cout << "invalid type" << std::endl;
      this->renderer = new VectorRenderer();
    }
  }
  void draw() override {
    std::cout << "Drawing circle" << std::endl;
    renderer->render();
  }
};

class Square : public Shape {
public:
  Square(){};
  Square(Type type) {
    if (type == Type::Raster)
      this->renderer = new RasterRenderer();
    else if (type == Type::Vector)
      this->renderer = new VectorRenderer();
    else {
      std::cout << "invalid type" << std::endl;
      this->renderer = new VectorRenderer();
    }
  }

  void draw() override {
    std::cout << "Drawing square" << std::endl;
    renderer->render();
  }
};

int main() {
  Shape *shape = new Circle(Type::Raster);
  shape->draw();
  shape->ChangeRenderer(Type::Vector);
  shape->draw();
  return 0;
}
