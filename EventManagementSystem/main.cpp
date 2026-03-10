#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Participant{
public:
    int id;
    string name;
    string contact;
    string category;
    bool payment;

    Participant(int i,string n,string c,string cat,bool p){
        id=i;
        name=n;
        contact=c;
        category=cat;
        payment=p;
    }
};

class Event{
public:
    int totalSeats;
    int bookedSeats;

    Event(int seats){
        totalSeats=seats;
        bookedSeats=0;
    }

    bool bookSeat(){
        if(bookedSeats<totalSeats){
            bookedSeats++;
            return true;
        }
        return false;
    }

    int availableSeats(){
        return totalSeats-bookedSeats;
    }
};

class RegistrationManager{
public:
    vector<Participant> participants;

    void registerParticipant(){
        int id;
        string name;
        string contact;
        string category;
        int pay;

        cout<<"Enter ID: ";
        cin>>id;

        for(auto &p:participants){
            if(p.id==id){
                cout<<"Duplicate ID\n";
                return;
            }
        }

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Contact: ";
        cin>>contact;

        cout<<"Enter Category: ";
        cin>>category;

        cout<<"Payment done? (1/0): ";
        cin>>pay;

        participants.push_back(Participant(id,name,contact,category,pay));
        cout<<"Participant Registered\n";
    }

    void showParticipants(){
        if(participants.empty()){
            cout<<"No participants\n";
            return;
        }

        for(auto &p:participants){
            cout<<"ID: "<<p.id<<" ";
            cout<<"Name: "<<p.name<<" ";
            cout<<"Contact: "<<p.contact<<" ";
            cout<<"Category: "<<p.category<<" ";
            cout<<"Payment: "<<(p.payment?"Paid":"Pending")<<"\n";
        }
    }

    void searchParticipant(){
        int id;
        cout<<"Enter ID: ";
        cin>>id;

        for(auto &p:participants){
            if(p.id==id){
                cout<<"Participant Found\n";
                cout<<p.id<<" "<<p.name<<" "<<p.contact<<" "<<p.category<<" "<<p.payment<<"\n";
                return;
            }
        }

        cout<<"Participant not found\n";
    }

    void deleteParticipant(){
        int id;
        cout<<"Enter ID: ";
        cin>>id;

        for(int i=0;i<participants.size();i++){
            if(participants[i].id==id){
                participants.erase(participants.begin()+i);
                cout<<"Participant Deleted\n";
                return;
            }
        }

        cout<<"Participant not found\n";
    }

    void generateReport(){
        int paid=0;
        int pending=0;

        for(auto &p:participants){
            if(p.payment) paid++;
            else pending++;
        }

        cout<<"Total Participants: "<<participants.size()<<"\n";
        cout<<"Paid: "<<paid<<"\n";
        cout<<"Pending: "<<pending<<"\n";
    }

    void exportData(){
        ofstream file("participants.txt");

        for(auto &p:participants){
            file<<p.id<<","<<p.name<<","<<p.contact<<","<<p.category<<","<<p.payment<<"\n";
        }

        file.close();

        cout<<"Data exported to participants.txt\n";
    }
};

int main(){

    Event event1(50);
    RegistrationManager manager;

    int choice;

    while(true){

        cout<<"\nSMART EVENT REGISTRATION SYSTEM\n";
        cout<<"1 Register Participant\n";
        cout<<"2 Show Participants\n";
        cout<<"3 Search Participant\n";
        cout<<"4 Delete Participant\n";
        cout<<"5 Generate Report\n";
        cout<<"6 Export Data\n";
        cout<<"7 Check Available Seats\n";
        cout<<"8 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                if(event1.bookSeat())
                    manager.registerParticipant();
                else
                    cout<<"Seats Full\n";
                break;

            case 2:
                manager.showParticipants();
                break;

            case 3:
                manager.searchParticipant();
                break;

            case 4:
                manager.deleteParticipant();
                break;

            case 5:
                manager.generateReport();
                break;

            case 6:
                manager.exportData();
                break;

            case 7:
                cout<<"Available Seats: "<<event1.availableSeats()<<"\n";
                break;

            case 8:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}