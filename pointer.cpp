using namespace std;
#include <iostream>
#include <string>
class point{
    public:

    int x;
    int* a;
    string s;
    string r;
    void print()
    {
        x=4564;
        a=&x;
        system("cls");
        cout<<"Value of X is "<<x<<endl;
        cout<<"Address of X is "<<a<<endl<<endl;
        cout<<"Value stored in POinter is "<< *a;

    }
    void hcases()
    {
        if(s.length()==0||s.length()==1)
        {
            cout<<"Invalid length of String";
        }
        bool spaceflag=false;
        int j;
        for(int i=0;i<s.length();i++)
        {
          if(s[i]==' ')
          {
            spaceflag=true;
          }
         if(s[i]!=' ')
         {
            r+=s[i];
         }
        };
        if(spaceflag==true)
        {
            cout<<endl<<"The Character Had whitespaces which were removed by the program"<<endl;
        }
    }
    void palindrome(){
        cout<<"Enter The Word to check palindrome "<<endl;
        getline(cin, s);
        bool flag;
        hcases();
        int i=0;
        int j=(r.length())-1;
        while(i<j)
        {
            if(r[i]==r[j])
            {
                flag=true;
            }
            if(r[i]!=r[j])
            {
                flag=false;
            }
            i++;j--;
        }
    if(flag)
    cout<<r<<" is a palindrome";
    else{
        cout<<r<<" is not a palindrome";
    }
}    

};
int main()
{
    point s1;
    s1.palindrome();

}
