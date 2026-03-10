#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event
{
private:
    string eventName;
    int totalSeats;
    int filledSeats;

public:
    Event();

    void createEvent();
    bool available();
    void bookSeat();
    void showSeats();
};

#endif