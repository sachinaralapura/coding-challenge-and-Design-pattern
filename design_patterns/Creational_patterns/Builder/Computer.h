#include <string>

// product class;
class Computer {
private:
  std::string _cpu;
  std::string _memory;
  std::string _storage;
  std::string _gpu;

public:
  void setCpu(std::string cpu) { this->_cpu = cpu; }
  void setMemory(std::string memory) { this->_memory = memory; }
  void setStorge(std::string storge) { this->_storage = storge; }
  void setGpu(std::string gpu) { this->_gpu = gpu; }
};

// builder abstract class
class ComputerBuilder {
public:
  virtual void BuildCpu(std::string) = 0;
  virtual void BuildGpu(std::string) = 0;
  virtual void BuildStorge(std::string) = 0;
  virtual void BuildMemory(std::string) = 0;
  virtual Computer getComputer() = 0;
};

// concrete class
class DeskTopComputer : public ComputerBuilder {
private:
  Computer _computer;

public:
  DeskTopComputer() { this->_computer = Computer(); }
  void BuildCpu(std::string cpu) { this->_computer.setCpu(cpu); }
  void BuildGpu(std::string gpu) { this->_computer.setGpu(gpu); }
  void BuildStorge(std::string storage) { this->_computer.setStorge(storage); }
  void BuildMemory(std::string memory) { this->_computer.setMemory(memory); }
  Computer getComputer() { return this->_computer; }
};
