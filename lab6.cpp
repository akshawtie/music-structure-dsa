#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }
    void push(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Currewntly Playing " << top->data << endl;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Current Queue:\n";
        while (temp != NULL) {
            cout << temp->data<<endl;
            temp = temp->next;
        }
        cout<<"==========================";
        cout<<endl<<endl<<endl;
    }
};

int main() {
    Stack s;
    int choice,no;
    string value;
    cout<<endl<<" enter number of songs to push";
    cin>>no;
    cin.ignore();
    for(int i=1;i<=no;i++)
    {
        cout<<"Enter The song to input"<<endl;
        getline(cin,value);
        s.push(value);
        system("cls");
        s.display();

    }

    do {
        
        s.peek();
        string val;
        cout<<"Enter Your choice \n1.Add another song\n2.Play Next\n3.View Whole queue\n4.Exit ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "add another song"<<endl;
                cin.ignore();
                getline(cin,val);
                s.push(val);
                break;

            case 2:
                s.pop();
                break;
            case 3:
                system("cls");
                s.display();
                break;

            case 4:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    system("cls");
    return 0;
}
