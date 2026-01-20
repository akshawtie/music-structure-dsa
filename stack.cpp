#include <iostream>
#include <string>
using namespace std;


class Stack
{
private:
    int size,top;
string *arr;

public:
    Stack(int s){
        size=s;
        top=-1;
        arr=new string[size];
    }
     Stack(){
    size = 0;
    top = -1;
    arr = nullptr;
    cout << "Welcome To Music Player\n";
}

    ~Stack(){
        delete[] arr;
    }

    bool isFull(){
        return top==size - 1;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(string x){
        if (isFull()) {
            cout<<"Stack Overflow!" << endl;
        } else {
            arr[++top]=x;
            cout<<x<<"pushed to stack." << endl;
        }
    }

    string pop(){
        if (isEmpty()) {
            cout<<"Stack Underflow!"<< endl;
            return "NO song";
        } else{
            return arr[top--];
        }
    }

    string peek() {
        if (isEmpty()){
            cout << "Stack is empty!" << endl;
            return "No song in queue";
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void menu(Stack &prev, Stack &next)
    {
       cout<<"Welcome to Music player"<<endl;
       cout<<"Enter a queue of atleast two songs"<<endl;
       int i=0;
       string s;
       
       while(i<2)
       {
        getline(cin,s);
        next.push(s);
        i++;
       }

    }
};
int main() 

    {
       Stack s1;
       Stack prev(20);
       Stack next(20);
       s1.menu(prev,next);
       cout<<next.peek()<<endl;
       next.pop();
       cout<<next.peek()<<endl;


       
    }

    