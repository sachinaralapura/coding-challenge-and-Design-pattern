#include "observer.h"

int main(int argc, char const *argv[])
{

    Observer *phone1 = new Phone();
    Observer *phone2 = new Phone();
    Observer *phone3 = new Phone();
    Observer *Tv1 = new TV();
    Observer *Tv2 = new TV();
    Observer *Tv3 = new TV();

    Observer *observers[] = {phone1, phone2, phone3, Tv1, Tv2, Tv3};

    Subject *subject = new WeatherStation();

    for (int i = 0; i < 6; i++)
    {
        subject->addObserver(observers[i]);
    }

    subject->updateWeather("sunny");

    return 0;
}
