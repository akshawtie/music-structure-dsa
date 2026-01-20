#include<iostream>
#include<string>
using namespace std;

class Stack{
private:
    int size,top;
    string *arr;

public:
    Stack(int s){
        size=s;
        top=-1;
        arr=new string[size];
    }

    ~Stack(){
        delete[] arr;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(string x){
        arr[++top]=x;
    }

    string pop(){
        if(isEmpty())
        return "No song";
        return arr[top--];
    }
};



class Queue{
private:
    int size,front,rear;
    string *arr;

public:
    Queue(int s){
        size=s;
        front=0;
        rear=-1;
        arr=new string[size];
    }

    ~Queue(){
        delete[] arr;
    }

    bool isEmpty(){
        return front>rear;
    }

    void pushqueue(string x){
        arr[++rear]=x;
    }

    string dequeue(){
        if(isEmpty())
        return "No song";
        return arr[front++];
    }
};

int main(){
    Stack prev(20);
    Queue next(20);

    int n;
    string song,current;

    cout<<"Enter number of songs:";
    cin>>n;
    cin.ignore();

    cout<<"Enter songs:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Song Number "<<i;
        getline(cin,song);
        next.pushqueue(song);
    }

    current=next.dequeue();
    cout<<"\nNow Playing: "<<current<<endl;

    int choice;
    do{
        cout<<"\n1.Next Song\n2.Previous Song\n3.Exit\ninput:";
        cin>>choice;

        if(choice==1){
            prev.push(current);
            current=next.dequeue();
            cout<<"Now Playing: "<<current<<endl;
        }

        else if(choice==2){
            if(current!="No song")
                next.pushqueue(current);
            current=prev.pop();
            cout<<"Now Playing: "<<current<<endl;
        }

    }while(choice!=3);

    return 0;
}

