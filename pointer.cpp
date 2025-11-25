using namespace std;
#include <iostream>
#include <string>
class point{
    public:
    string s;
    string r;
    
    string hcases()
    {
        if(s.length()==0||s.length()==1)
        {
            cout<<"Invalid length of String";
            exit(0);
        }
        bool spaceflag=false;
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
        return r;
    }
    void palindrome(){
        cout<<"Enter The Word to check palindrome "<<endl;
        getline(cin, s);
        bool flag=true;
        s=hcases();
        int i=0;
        int j=(s.length())-1;
        while(i<j && flag)
        {
            if(s[i]==r[j])
            {
                flag=true;
            }
            if(s[i]!=r[j])
            {
                flag=false;
            }
            i++;j--;
        }
    if(flag)
    cout<<s<<" is a palindrome";
    else{
        cout<<s<<" is not a palindrome";
    }
}    

};
int main()
{
    point s1;
    s1.palindrome();

}
