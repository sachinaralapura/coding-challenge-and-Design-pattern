// Suppose you have a legacy printer class that only understands commands in
// uppercase, and a modern computer class that sends commands in lowercase. You
// need to make the modern computer work with the legacy printer without
// modifying the existing printer class.

// LegacyPrinter Class
#include <cctype>
#include <iostream>
#include <string>
class LegacyPrinter {
public:
  void printInUppercase(std::string text) { std::cout << text << std::endl; }
};

// ModernComputer Class
class ModernComputer {
public:
  virtual void sendCommand(std::string) = 0;
};

// Adapter class to make the LegacyPrinter compatible with ModernComputer
class printerAdapter : public ModernComputer {
private:
  LegacyPrinter legacy_printer;

public:
  printerAdapter(){};
  void sendCommand(std::string text) {
    std::string upperCaseText = text;
    for (char &x : upperCaseText) {
      x = toupper(x);
    }
    this->legacy_printer.printInUppercase(upperCaseText);
  }
};

int main() {
  printerAdapter adapter;
  adapter.sendCommand("sachin");
  return 0;
}
