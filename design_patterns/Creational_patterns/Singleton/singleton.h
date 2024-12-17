#include <iostream>
#include <string>
class DataBase {
private:
  DataBase() { std::cout << "A new instance is created" << std::endl; };
  ~DataBase() {}
  DataBase(const DataBase &) = delete;
  DataBase &operator=(const DataBase &) = delete;

  static DataBase *connection_instance;

public:
  static DataBase *getInstance();
  void query(std::string);
};

DataBase *DataBase::connection_instance = nullptr;
DataBase *DataBase::getInstance() {
  if (connection_instance == nullptr) {
    connection_instance = new DataBase();
    return connection_instance;
  }
  return connection_instance;
};

void DataBase::query(std::string query) {
  std::cout << "executing query : " << query << std::endl;
}
