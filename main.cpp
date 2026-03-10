#include <iostream>
#include "Participant.h"
#include "Event.h"
#include "RegistrationManager.h"
#include "ReportGenerator.h"
#include "FileManager.h"

using namespace std;

int main()
{
    Event event;
    RegistrationManager manager;

    int choice;

    while(true)
    {
        cout<<"\n===== Event Management System =====\n";
        cout<<"1 Create Event\n";
        cout<<"2 Register Participant\n";
        cout<<"3 Show Participants\n";
        cout<<"4 Seat Report\n";
        cout<<"5 Exit\n";

        cin>>choice;

        if(choice==1)
        {
            event.createEvent();
        }

        else if(choice==2)
        {
            if(event.available())
            {
                manager.addParticipant();
                event.bookSeat();
            }
            else
            {
                cout<<"Seats Full\n";
            }
        }

        else if(choice==3)
        {
            manager.showParticipants();
        }

        else if(choice==4)
        {
            event.showSeats();
        }

        else if(choice==5)
        {
            FileManager::save();
            break;
        }
    }

    return 0;
}