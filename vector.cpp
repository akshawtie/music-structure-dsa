#include <iostream>
#include <vector>
using namespace std;

class abdca{
    public:
    vector <int> v={1};
    void hell()
    {
        v.push_back(5);

        cout<<v[1];
        cout<<endl<<v[0];
        cout<<endl<<"capacity is"<<v.capacity();

    }


};
int main()
{
    abdca s;
    s.hell();

}