#include <iostream>
#include <list>
using namespace std;

// ---------------------- abstract observer ----------------------

class Observer
{
public:
    virtual void update(string) = 0;
    virtual void display() {};
};

// ---------------------- abstract subject -----------------------

class Subject
{
public:
    virtual void addObserver(Observer *) = 0;
    virtual void removerObserver(Observer *) = 0;
    virtual void notify() = 0;
    virtual void updateWeather(string weather){}
    virtual void setWeather(string) {}
    virtual string getWeather() const { return ""; }
};

// ---------------------- concrete Subject ----------------------

class WeatherStation : public Subject
{

private:
    list<Observer *> *observers;
    string weather;

public:
    WeatherStation()
    {
        this->observers = new list<Observer *>();
    };
    void setWeather(string weather) { this->weather = weather; };
    string getWeather() const { return this->weather; };
    void addObserver(Observer *observer) override
    {
        this->observers->push_back(observer);
    };
    void removerObserver(Observer *observer) override
    {
        this->observers->remove(observer);
    }
    void updateWeather(string weather)
    {
        this->setWeather(weather);
        this->notify();
    }
    void notify()
    {
        for (auto observer : *this->observers)
        {
            observer->update(this->weather);
        }
    }
};

// ---------------------- concrete Observer ----------------------

class Phone : public Observer
{
private:
    string weather;

public:
    void update(string weather) override
    {
        this->weather = weather;
        this->display();
    }
    void display()
    {
        cout << "Phone Display : Weather updated -" << this->weather << endl;
    }
};

// ---------------------- concrete Observer ----------------------

class TV : public Observer
{
private:
    string weather;

public:
    void update(string weather) override
    {
        this->weather = weather;
        this->display();
    }
    void display()
    {
        cout << "TV Display : Weather updated -" << this->weather << endl;
    }
};
