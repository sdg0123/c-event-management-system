#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
using namespace std;

class Participant
{
public:
    int id;
    string name;
    string contact;
    string category;
    string paymentStatus;

    Participant();

    void input();
    void display();
};

#endif