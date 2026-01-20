#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Text{
private:
    vector<char> name;

public:
    Text(const string&s){
        for(char c:s)name.push_back(c);
    }

    void to_lower(){
        for(size_t i=0;i<name.size();i++){
            if(name.at(i)>='A'&&name.at(i)<='Z')
                name.at(i)+=('a'-'A');
        }
    }

    void remove_spaces(){
        for(size_t i=0;i<name.size();i++){
            if(name.at(i)==' '){
                name.erase(name.begin()+i);
                i--;
            }
        }
    }

    bool is_palindrome(){
        if(name.size()==0)return true;
        size_t left=0,right=name.size()-1;
        while(left<right){
            if(name.at(left)!=name.at(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool is_same(const Text&other){
        if(name.size()!=other.name.size())return false;
        for(size_t i=0;i<name.size();i++)
            if(name.at(i)!=other.name.at(i))return false;
        return true;
    }

    void merge(const Text&other){
        name.insert(name.end(),other.name.begin(),other.name.end());
    }

    string get(){
        string s;
        for(char c:name)s+=c;
        return s;
    }
};

int main(){
    Text t1("");
    string input;
    int choice;

    cout<<"Enter initial name:";
    getline(cin,input);
    t1=Text(input);

    do{
        cout<<"\n=====MENU=====\n";
        cout<<"1.Check palindrome\n";
        cout<<"2.Compare with another name\n";
        cout<<"3.Merge with another name\n";
        cout<<"4.Display current name\n";
        cout<<"5.Re-enter name\n";
        cout<<"6.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;
        cin.ignore();

        switch(choice){
        case 1:
            cout<<"Palindrome:"<<(t1.is_palindrome()?"Yes":"No")<<endl;
            break;

        case 2:{
            cout<<"Enter second name:";
            getline(cin,input);
            Text t2(input);
            t2.to_lower();
            t2.remove_spaces();
            cout<<(t1.is_same(t2)?"Both names are same.":"Names are different.")<<endl;
            break;
        }

        case 3:{
            cout<<"Enter name to merge:";
            getline(cin,input);
            Text t2(input);
            t1.merge(t2);
            cout<<"Names merged.\n";
            break;
        }

        case 4:
            cout<<"Current name:"<<t1.get()<<endl;
            break;

        case 5:
            cout<<"Enter new name:";
            getline(cin,input);
            t1=Text(input);
            cout<<"Name updated.\n";
            break;

        case 6:
            cout<<"Exiting...\n";
            return 0;

        default:
            cout<<"Invalid choice.\n";
        }

    }while(choice!=6);

    return 0;
}
