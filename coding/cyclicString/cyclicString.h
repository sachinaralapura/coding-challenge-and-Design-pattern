#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() {
        next = 0;
    }
    Node(T data, Node<T>* next = 0) {
        this->data = data;
        this->next = next;
    }
    T getData() {
        return this->data;
    }
};

template <class T>
class CircularLL {
private:
    Node<T>* tail;

public:
    CircularLL() {
        this->tail = 0;
    }


    ~CircularLL() {
        Node<T>* temp = tail->next;
        for (Node<T>* t = temp->next; t != tail; t = tail->next) {
            delete temp;
            temp = t;
        }
        delete tail;
    }

    bool isEmpty() const {
        return tail == 0;
    }

    int length() {
        int len;
        if (isEmpty())
            return 0;

        Node<T>* temp = tail->next;
        for (len = 0; temp != tail; temp = temp->next, len++)
            ;
        return ++len;
    }

    void push(T el) {
        if (this->isEmpty()) {
            this->tail = new Node<T>(el);
            this->tail->next = tail;
        } else {
            this->tail->next = new Node<T>(el, tail->next);
            this->tail = this->tail->next;
        }
    }

    Node<T>* getTail() {
        return tail;
    }

    void pushNode(Node<T>* node) {
        if (this->isEmpty()) {
            this->tail = node;
            this->tail->next = tail;
        } else {
            this->tail->next = node;
            this->tail = this->tail->next;
        }
    }


    void remove(Node <T>* node) {
        if (isEmpty()) {
            return;
        }
        if (node->next == node) {
            tail = 0;
            delete node;
            return;
        }

        Node<T>* temp = node;
        while (temp->next != node) {
            temp = temp->next;
        }
        if (node == tail) {
            tail = temp;
        }
        temp->next = node->next;
        delete node;
    }

    T& operator[](int index) {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* current = tail->next;
        for (int i = 0; i < index; ++i) {
            if (current == tail) {
                current = tail;
                break;
            }
            current = current->next;
        }
        return current->data;
    }


    void display() const {
        if (isEmpty()) {
            return;
        }
        Node<T>* tmp = 0;
        for (tmp = this->tail->next; tmp != this->tail; tmp = tmp->next)
            cout << tmp->data << " --> ";
        cout << tail->data << " --> " << tail->next->data << endl;
    }
};

class StringCyclic {
private:
    CircularLL<char>* list;

public:
    StringCyclic() {
        this->list = new CircularLL<char>();
    }
    StringCyclic(string str) {
        this->list = new CircularLL<char>();
        for (char s : str) {
            this->list->push(s);
        }
    }

    string cyclicSlice(int k) {

        string output = "";

        CircularLL<int>* index = new CircularLL<int>();
        for (int i = 0; i < list->length(); i++) {
            index->push(i);
        }
        Node<int>* indexP = index->getTail();


        for (int i = 0; i < k; i++)
            indexP = indexP->next;

        while (!(index->isEmpty())) {
            output.push_back((*list)[indexP->getData()]);
            Node<int>* temp = indexP;
            for (int i = 0; i < k; i++)
                indexP = indexP->next;
            if (temp == indexP) {
                indexP = indexP->next;
            }
            index->remove(temp);
        }
        return output;
    }
};
