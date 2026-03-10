#include <iostream>
#include "Event.h"
using namespace std;

Event::Event()
{
    filledSeats = 0;
}

void Event::createEvent()
{
    cout<<"Enter Event Name: ";
    cin>>eventName;

    cout<<"Enter Total Seats: ";
    cin>>totalSeats;
}

bool Event::available()
{
    return filledSeats < totalSeats;
}

void Event::bookSeat()
{
    filledSeats++;
}

void Event::showSeats()
{
    cout<<"Total Seats: "<<totalSeats<<endl;
    cout<<"Filled Seats: "<<filledSeats<<endl;
    cout<<"Available Seats: "<<totalSeats - filledSeats<<endl;
}