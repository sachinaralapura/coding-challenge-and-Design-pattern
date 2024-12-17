#include "singleton.h"
int main() {
  DataBase *connection1 = DataBase::getInstance();
  connection1->query("SLdfk");

  DataBase *connection2 = DataBase::getInstance();
  connection2->query("sllsdklijfsldf");
  return 0;
}
