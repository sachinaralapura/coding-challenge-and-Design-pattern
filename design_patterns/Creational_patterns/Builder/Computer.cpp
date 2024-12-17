#include "Computer.h"

enum CONFIG { DEFAULT, AMD, INTEL };
// Director class
class ComputerAssembler {
public:
  Computer assemble(ComputerBuilder *builder, CONFIG config) {
    if (config == CONFIG::AMD) {
      builder->BuildCpu("Amd Ryzen 5");
      builder->BuildGpu("Nvidia RTX 3050");
      builder->BuildMemory("16 GPU");
      builder->BuildStorge("1 TB");
      return builder->getComputer();
    } else if (config == CONFIG::INTEL) {
      builder->BuildCpu("INTEL i7");
      builder->BuildGpu("Nvidia RTX 3050");
      builder->BuildMemory("16 GPU");
      builder->BuildStorge("1 TB");
      return builder->getComputer();
    }
    builder->BuildCpu("Intel i5");
    builder->BuildGpu("Nvidia GTX 1650");
    builder->BuildMemory("8 GPU");
    builder->BuildStorge("500 GB");
    return builder->getComputer();
  }
};

int main() {
  ComputerBuilder *builder = new DeskTopComputer();
  ComputerAssembler *assembler = new ComputerAssembler();

  Computer desktopcomputer = assembler->assemble(builder, CONFIG::AMD);

  return 0;
}
