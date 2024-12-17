#include <string>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <iostream>
// Flyweight
// enum BOOKTYPES
// {
//   FAN_SAP,
//   FAN_HEM,
//   HOR_SAP,
//   HOR_HEM,
//   SCI_SAP,
//   SCI_HEM
// };

std::string toUpperCase(std::string str)
{
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

class Book
{
public:
  virtual std::string getDescription() = 0;
};

// concrete FlyWeight
class BookType : public Book
{
public:
  BookType(std::string type, std::string distributor)
  {
    this->type = type;
    this->distributor = distributor;
  }

  std::string getDescription() override
  {
    return this->type + " " + this->distributor;
  }

private:
  std::string type;        // fantasy , Horror , sci-fi
  std::string distributor; // sapna , hema
};

// unsharedConcreteFlyweight
class Books : public Book
{
private:
  std::string name;
  double price;
  BookType *bookType;

public:
  Books(std::string name, double price, BookType *btype)
  {
    this->name = name;
    this->price = price, this->bookType = btype;
  }

  std::string getDescription()
  {
    return this->name + " " + std::to_string(this->price) + " " +
           this->bookType->getDescription();
  }

  BookType *getBookType() { return this->bookType; }
};

// FlyWeight Factory
class BookFactory
{
private:
  std::unordered_map<std::string, BookType *> bookTypes;

public:
  Books *getBooks(std::string name, double price, std::string type, std::string distributor)
  {
    std::string key = toUpperCase(type + distributor);
    std::unordered_map<std::string, BookType *>::iterator booktypeIterator = this->bookTypes.find(key);

    if (booktypeIterator == this->bookTypes.end())
    {
      BookType *temp = new BookType(type, distributor);
      this->bookTypes.insert({toUpperCase(type + distributor), temp});
      return new Books(name, price, temp);
    }
    return new Books(name, price, booktypeIterator->second);
  }
};

class BookStore
{
private:
  std::list<Books *> bookList;
  BookFactory *factory = new BookFactory();
  std::string storeName;

public:
  BookStore(){};
  BookStore(std::string name) : storeName(name){};
  BookStore(std::string name, std::list<Books *> bookslist) : storeName(name), bookList(bookList){};
  void addBook(std::string, double, std::string, std::string);
  std::list<Books *> getBookList() const { return this->bookList; }
};

void BookStore::addBook(std::string name, double price, std::string type, std::string distributor)
{
  Books *newBook = this->factory->getBooks(name, price, type, distributor);
  this->bookList.push_back(newBook);
}