using namespace std;
#include <iostream>
#include <string>
class point{
    public:

    int x;
    int* a;
    void print()
    {
        x=4564;
        a=&x;
        system("cls");
        cout<<"Value of X is "<<x<<endl;
        cout<<"Address of X is "<<a<<endl<<endl;
        cout<<"Value stored in POinter is "<< *a;

    }
    void palindrome(){
        string a;
        cout<<"Enter The Word to check palindrome";
        cin>>a;
        bool flag;
        int i=0;
        int j=(a.length())-1;
        while(i<j)
        {
            if(a[i]==a[j])
            {
                flag=true;
            }
            if(a[i]!=a[j])
            {
                flag=false;
            }
            i++;j--;
        }
    if(flag)
    cout<<a<<" is a palindrome";
    else{
        cout<<a<<" is not a palindrome";
    }
}    
};
int main()
{
    point s1;
    s1.palindrome();

}
