#include <iostream>
using namespace std;
 
class arshu

{
public:
int fact;
void recur(int n){
n--;
fact=fact+(fact*n);

if(n<1)
{
    cout<<fact;
    return;
}
recur(n-1);
}};
int main()
{
    arshu s2;
    s2.recur(5);
}