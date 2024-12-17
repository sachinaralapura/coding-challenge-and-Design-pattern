#include "flyweight.h"

int main(int argc, char const *argv[])
{

    BookStore manjunath;
    manjunath.addBook("Crime and Punishment", 300.0, "CRIME", "SAPNA");
    manjunath.addBook("MetaMorphasis", 200.0, "CRIME", "SAPNA");
    std::list<Books *> bookslist = manjunath.getBookList();

    for (std::list<Books *>::iterator iter = bookslist.begin(); iter != bookslist.end(); iter++)
    {
        std::cout << (*iter)->getDescription() << std::endl;
        std::cout << (*iter)->getBookType() << std::endl;
    }

    return 0;
}
