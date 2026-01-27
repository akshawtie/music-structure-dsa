#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>

using json = nlohmann::json;
using namespace std;

struct Node{
    string patientName;
    int age;
    int patientID;
    Node* prev;
    Node* next;

    Node(string name,int a,int id) {
        patientName = name;
        age = a;
        patientID = id;
        prev = NULL;
        next = NULL;
    }
};

class HospitalQueue{
private:
    Node* head;
    Node* tail;
    int idCounter = 100; 
public:
     int length=0;
     Node* current;
     Node* start;

    HospitalQueue() {
        head=NULL;
        tail=NULL;
    }
    void registerPatient(string name,int age) {
        idCounter++;
        Node* newNode = new Node(name, age, idCounter);

        if (head==NULL) {
            head=tail=current=start=newNode;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }
    // used for initializing from json file 
    void loadPatient(string name,int age,int id) {
        Node* newNode = new Node(name, age, id);
        if (id > idCounter) idCounter = id;

        if (head == NULL) {
            head = tail = current = start = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }

    // displays the current hospital registry
    void displayRegistry() {
        Node* curr = head;
        int i=1;
        while (curr != NULL) {
            cout<<i<<". [ID: "<<curr->patientID<<"] "<<curr->patientName;
            cout<<" (Age: "<<curr->age<<")"<<endl<<endl;
            curr=curr->next;
            i++;
        }

        cout<<"\n\n";
    }

    void addAtPriority(int pos,string name,int age)
    {
       idCounter++;
       Node* curr=head;
       for(int a=1; a<pos; a++)
       {
        if(curr->next==NULL)
        {
            cout<<"Invalid Position\n";
            return;
        }else{
        curr=curr->next;
        }}
    
    Node* temp=curr->next; // pointing to the node currently after our target position
    Node* newNode = new Node(name, age, idCounter);
    newNode->next=temp;
    newNode->prev=curr;
    curr->next=newNode;
    if(temp != NULL) {
        temp->prev=newNode;
    } else {
        tail = newNode;
    }
    }
    
        void del (int sid){
        Node* curr=head;
        bool flag=false;

        while(curr!=NULL){  
            if(curr->patientID==sid)  {
                flag=true;
                if(curr==head){
                    head=curr->next;
                    if(head!=NULL) head->prev=NULL;
                    if(curr==tail) tail=NULL; 
                }
                else if(curr==tail){
                    tail=curr->prev;
                    if(tail!=NULL) tail->next=NULL;
                }
                // deleting from the Middle
                else{
                    curr->prev->next=curr->next;
                    curr->next->prev=curr->prev;
                }
                // if the patient being treated is the one deleted
                if(current==curr){
                    if(curr->next!=NULL) current=curr->next;
                    else current=head;
                }
                delete curr;
                cout<<"Patient Discharged Successfully"<<endl;
                length--;
                return;
            }
            curr=curr->next;
        }
        if(flag==false)
        {
            cout<<"No patient found with that ID"<<endl;
        }
    }

    void search(int sid){
        Node* curr=head;
        bool flag=false;
        while(curr!=NULL){  
            if(curr->patientID==sid) 
            {
                cout<<"Patient Found"<<endl;
                cout<<"Name: "<<curr->patientName<<endl<<"Age: "<<curr->age<<endl;
                flag=true;
                break;
            }
            curr=curr->next;
        }
        if(flag==false)
        {
            cout<<"No patient found"<<endl;
        }
    }
    void exitwrite()
    {
        json j;
        ofstream out("hospital_data.json");
        j["patients"]=json::array();

        Node* curr = head;
        while (curr != NULL) {
             j["patients"].push_back({
            {"name", curr->patientName}, {"age", curr->age}, {"id", curr->patientID}});
            curr = curr->next;
            cout<<endl<<"=============="<<endl;
        }
        out<<j.dump(2);
        out.close();
    }
};

int main(){

    ifstream file("hospital_data.json");
    HospitalQueue hospital;
    
    if(file.is_open()){
        json j;
        file>>j;
        for (auto& p : j["patients"])
        {
            hospital.loadPatient(p.value("name","Unknown"),p.value("age",0),p.value("id",0));
        }
        file.close();
    }

    int choice;
    cout<<"Welcome to Hospital Management System"<<endl;
    cout<<"1.View Patient Registry\n2.Exit\n";
    cin>>choice;

    while(choice>2 || choice<1){
        cout<<"Invalid Input! Try Again"<<endl;
        cin>>choice;
    }

    switch(choice)
    {
    case 1:
    {
    system("cls");
    hospital.displayRegistry();
    bool flag=true;
    while(flag){
        if(hospital.current != NULL) {
            cout<<"Currently treating: "<<hospital.current->patientName<<" (Age: "<<hospital.current->age<<")"<<endl;
        }
        cout<<"1.Next Patient\n2.Previous Patient\n3.Register New Patient\n4.Emergency Insert at Index\n5.Search\n6.Finish Treating Patient\n7.Show Entire Directory\n8.Exit"<<endl;
        int num;
        cin>>num;
        if(num==1){
            if(hospital.current->next==NULL)
            {
                cout<<"End of queue. Reverting to start...";
                hospital.current=hospital.start;
            }
            else{
                hospital.current=hospital.current->next;
            }
        }
        if(num==2){
            if(hospital.current->prev==NULL)
            {
                cout<<"Already at the first patient!"<<endl;
            }
            else{
                hospital.current=hospital.current->prev;
            }
        }
        if(num==3){
            string name; int age;
            cout<<"Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter Age: ";
            cin>>age;
            hospital.registerPatient(name, age);
        }
        if(num==4)
        {
            int pos;
            cout<<"Please enter index: ";
            cin>>pos;
            cout<<"\nEnter Patient Name: ";
            string name; int age;
            cin.ignore();
            getline(cin, name); 
            cout<<"\nEnter Age: ";
            cin>>age;
            hospital.addAtPriority(pos, name, age);
        }
        if(num==5){
            int sid;
            cout<<endl<<"Enter patient ID: "; 
            cin>>sid;
            hospital.search(sid);

        }
        if(num==6){
            int sid;
            hospital.displayRegistry();
            cout<<endl<<"Enter patient ID to discharge: ";
            cin>>sid;
            hospital.del(sid);
            
        }
        if(num==7){
            hospital.displayRegistry();
        }
        if(num==8){
            flag=false;
            hospital.exitwrite();
        }
    }}
    break;
    case 2:
    hospital.exitwrite();
    break;
    }

    return 0;
}