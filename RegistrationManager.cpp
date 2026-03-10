#include <iostream>
#include "RegistrationManager.h"

using namespace std;

void RegistrationManager::addParticipant()
{
    Participant p;
    p.input();
    participants.push_back(p);

    cout<<"Participant Registered Successfully\n";
}

void RegistrationManager::showParticipants()
{
    for(auto &p : participants)
    {
        p.display();
    }
}