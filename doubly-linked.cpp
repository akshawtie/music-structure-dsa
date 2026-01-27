#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>

using json = nlohmann::json;
using namespace std;

struct Node {
    string name;
    string artist;
    Node* prev;
    Node* next;

    Node(string value,string value2) {
        name = value;
        artist=value2;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
   

public:
     Node* play;
     Node* start;
    DoublyLinkedList() {
        head=NULL;
        tail=NULL;
    }

    // Insert at end, is being used to append to the json
    void insertEnd(string value,string value2) {
        Node* newNode = new Node(value,value2);

        if (head==NULL) {
            head=tail=play=start=newNode;
            return;
        }

        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }


    // Insert at beginning, is being used to initialize the linked list with data from json
    void insertFront(string value,string value2) {
        Node* newNode = new Node(value,value2);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    bool isInteger(const string& s) {
    if (s.empty()) return false;

    int i = 0;
    if (s[0] =='-'|| s[0]=='+')i=1;

    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

    // Delete from front, currently not in use
    void deleteFront() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    // Delete from end, currently not in use
    void deleteEnd() {
        if (tail == NULL) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }

    //displays the linked list from the head
    void displayForward() {
        Node* curr = head;
        int i=1;
        while (curr != NULL) {
            cout<<i<<" "<<curr->name<<" by ";
            cout<<curr->artist<<endl<<endl;
            curr=curr->next;
            i++;
            
        }

        cout<<"\n\n";
    }
    //displays from tail, idk why i made it im not using it,
    void displayBackward() {
        Node* curr = tail;
        while (curr != NULL) {
            cout<<curr->name;
            cout<<curr->artist<<" <-> ";
            curr=curr->prev;
        }
        cout << "NULL\n";
    }
    void addatindex(int pos,string song,string art)
    {
       Node* curr=head;
       int a=1;
       for(int a=1;a<pos;a++)
       {
        if(curr->next==NULL)
        {
            cout<<"Invalid Position/n";
        }else{
        curr=curr->next;
    }}
    // temp variable is used to store the curr+1 element's address so it can be used to link the element
    Node* temp=curr->next->next;
    Node* newnode =new Node(song,art);
    temp->prev=newnode;
    newnode->prev=curr;
    curr->next=newnode;
    newnode->next=temp;
    newnode->artist=art;
    newnode->name=song;
    
     
    }
    // exitwrites overwrites the existing json with the linked list loaded in memory.
    void exitwrite()
    {
        json j;
        ofstream out("playlist.json");
        j["playlist"]=json::array();

        Node* curr = head;
        while (curr != NULL) {
             j["playlist"].push_back({
            {"title",curr->name},{"artist",curr->artist}});
            curr = curr->next;
            cout<<endl<<"=============="<<endl;
        }
        out<<j.dump(2);
        out.close();
    }
};

int main(){

    ifstream file("playlist.json");
    json j;
    file>>j;
    json i;
    DoublyLinkedList list;
    int choice;
    for (auto& song:j["playlist"])
    {
        list.insertEnd(song.value("title","unknown"),song.value("artist","unknown"));
    }
    cout<<"Welcome to Spicify"<<endl;
    cout<<"1.View Your Playlist\n2.Exit\n";
    cin>>choice;
    while(choice>2||choice<1){
        cout<<"Invalid Input!Try Again"<<endl;
     cin>>choice;
}
    switch(choice)
    {
    case 1:
    {
    system("cls");
    list.displayForward();
    bool flag=true;
    while(flag){
        int num;
        cout<<"Currently playing "<<list.play->name<<" by "<<list.play->artist<<endl;
        cout<<"1.Play Next\n2.Play Previous\n3.Add another song\n4.Add at index\n5.Exit"<<endl;
        cin>>num;
        if(num==1){
            if(list.play->next==NULL)
            {
                cout<<"At the End of playlist,Looping From Start";
                list.play=list.start;
            }
            else{
           list.play=list.play->next;
        }}
        if(num==2){
            if(list.play->prev==NULL)
            {
                cout<<"At the start of the playlist"<<endl;
            }
            else{
                list.play=list.play->prev;
            }
        }
        if(num==3){
            string art,song;
            cout<<"Enter Song name";
            cin.ignore();
            getline(cin,song);
            cout<<"Enter artist name";
            getline(cin,art);
            list.insertEnd(song,art);
        }
        if(num==4)
        {
            int pos;
            cout<<"Please enter index";
            cin>>(pos);
            cout<<"\nEnter Song Name";
            string song,art;
            cin.ignore();
            getline(cin,song); 
            cout<<"\nEnter Artist Name";
            getline(cin,art);
            list.addatindex(pos,song,art);
        }
        if(num==5){
            flag=false;
            list.exitwrite();
        }
    }}
    break;
    case 2:
    list.exitwrite();
    break;
}
}