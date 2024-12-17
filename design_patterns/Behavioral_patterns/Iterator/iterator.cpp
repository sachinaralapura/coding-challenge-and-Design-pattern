#include <iostream>
#include <list>
#include <vector>
using namespace std;

class IteratorOutOfBounds
{
public:
    string what() const
    {
        return "Iterator Index is out of bound";
    }
};
//----------------------------------- Abstract Iterator -----------------------------------

template <class Item>
class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Item CurrentItem() const = 0;

protected:
    Iterator() {};
};

// ----------------------------------- abstract List  -----------------------------------

template <class Item>
class AbstractList
{
public:
    virtual Iterator<Item> *createIterator() const = 0;
    virtual long Count() const = 0;
    virtual Item First() const = 0;
    virtual Item Last() const = 0;
    virtual Item Get(long index) const = 0;
    virtual void append(Item item) = 0;
};

// ----------------------------------- Concrete Iterator -----------------------------------

template <class Item>
class ListIterator : public Iterator<Item>
{
public:
    ListIterator(const AbstractList<Item> *aList);
    void First() override;
    void Next() override;
    bool IsDone() const override;
    Item CurrentItem() const override;

private:
    const AbstractList<Item> *_list;
    long _current;
};

template <class Item>
ListIterator<Item>::ListIterator(const AbstractList<Item> *aList) : _list(aList), _current(0) {}

template <class Item>
void ListIterator<Item>::First()
{
    this->_current = 0;
}

template <class Item>
void ListIterator<Item>::Next()
{
    this->_current++;
}

template <class Item>
bool ListIterator<Item>::IsDone() const
{
    return this->_current >= this->_list->Count();
}

template <class Item>
Item ListIterator<Item>::CurrentItem() const
{
    if (IsDone())
    {
        throw IteratorOutOfBounds();
    }
    return this->_list->Get(_current);
}

// ----------------------------------- concrete List -----------------------------------

template <class Item>
class List : public AbstractList<Item>
{
public:
    List(long size = 0)
    {
        this->_item = new vector<Item>;
        this->size = size;
        this->current = 0;
    }

    Iterator<Item> *createIterator() const override
    {
        return new ListIterator<Item>(this);
    }

    long Count() const { return this->size; }
    Item First() const { return this->_item->front(); }
    Item Last() const { return this->_item->back(); }
    Item Get(long index) const
    {
        if (index < size)
            return (*this->_item)[index];
        throw IteratorOutOfBounds();
    }
    void append(Item item)
    {
        this->current++;
        this->_item->push_back(item);
    }

private:
    vector<Item> *_item;
    long size;
    long current;
};



// ----------------------------------- Employee -----------------------------------
class Employee
{
public:
    Employee() {}
    Employee(string n, double a) { this->name = n, this->age = a; }
    string getName() const { return this->name; }
    double getAge() const { return this->age; }
    friend ostream &operator<<(ostream &out, const Employee &);
    friend ostream &operator<<(ostream &out, const Employee *);

private:
    string name;
    double age;
};

ostream &operator<<(ostream &out, const Employee &emp)
{
    out << emp.getName() << " " << emp.getAge() << " ";
    return out;
}

ostream &operator<<(ostream &out, const Employee *emp)
{
    out << emp->getName() << " " << emp->getAge() << " ";
    return out;
}

// ----------------------------------- -----------------------------------

void PrintEmployee(Iterator<Employee *> &e)
{
    for (e.First(); !e.IsDone(); e.Next())
        cout << e.CurrentItem() << endl;
}

// ----------------------------------- -----------------------------------

int main(int argc, char const *argv[])
{
    List<Employee *> *employees = new List<Employee *>(3);

    employees->append(new Employee("sachin ", 22));
    employees->append(new Employee("Nigger ", 21));
    employees->append(new Employee("Lest ", 20));

    Iterator<Employee *> *listIterator = new ListIterator<Employee *>(employees);
    try
    {
        PrintEmployee(*listIterator);
    }
    catch (const IteratorOutOfBounds &e)
    {
        cerr
            << e.what() << '\n';
    }

    return 0;
}
