#include <iostream>
#include "Participant.h"
using namespace std;

Participant::Participant()
{
}

void Participant::input()
{
    cout<<"Enter ID: ";
    cin>>id;

    cout<<"Enter Name: ";
    cin>>name;

    cout<<"Enter Contact: ";
    cin>>contact;

    cout<<"Enter Category: ";
    cin>>category;

    cout<<"Payment Status (Paid/Unpaid): ";
    cin>>paymentStatus;
}

void Participant::display()
{
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Contact: "<<contact<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Payment: "<<paymentStatus<<endl;
    cout<<"--------------------"<<endl;
}