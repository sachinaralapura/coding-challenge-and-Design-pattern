#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> *lst =  new vector<int>;
    lst->push_back(12);
    lst->push_back(2);
    lst->push_back(1);
    lst->push_back(34);
    int l = (*lst)[1];
    return 0;
}
