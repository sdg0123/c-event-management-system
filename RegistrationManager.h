#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <vector>
#include "Participant.h"

using namespace std;

class RegistrationManager
{
private:
    vector<Participant> participants;

public:
    void addParticipant();
    void showParticipants();
};

#endif