using namespace std;
#include<iostream>
#include<vector>

class point{
public:
    vector<char>s;

    void palindrome(){
        cout<<"Enter the word to check palindrome"<<endl;

        string temp;
        getline(cin,temp);

       //egde cases elimination is done here
        for(char c:temp){
            if(c!=' '){
                if(c>='A'&&c<='Z')
                c+=32;
                s.push_back(c);
            }
        }

        if(s.size()<=1){
            cout<<"Invalid length of String";
            return;
        }

        bool flag=true;
        int i=0,j=s.size()-1;

        while(i<j){
            if(s[i]!=s[j]){
                flag=false;
                break;
            }
            i++;j--;
        }

        if(flag)
            cout<<"Given word is a palindrome";
        else
            cout<<"Given word is not a palindrome";
    }
};

int main(){
    point s1;
    s1.palindrome();
    return 0;
}
