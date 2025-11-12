#include <iostream>
using namespace std;


class sparse{


    public:
     int rows, cols;
     bool sparse_flag;
     int count=0;
    int **matrix;
     void input();
     void check();
     void triplet();
     void search();
     int total;
     int **matrix2;
     int nonsparse;


};
 void sparse::input()
 {
    cout<<"enter the amount of columns"<<endl;
    cin>>cols;
    cout<<"enter the amount of rows"<<endl;
    cin>>rows;
    matrix=new int*[rows];
    for(int i=0;i<rows;i++)
    {
    matrix[i]=new int[cols];
    }
    cout<<"Matrix Created of"<<rows<<"*"<<cols<<endl;
    cout<<endl<<endl<<"=========Enter Values=========";


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
      cout<<endl<<"Rows "<<i+1<<" Column "<<j+1<<endl;
      cin>>matrix[i][j];
}}}


void sparse::check(){
total=rows*cols;
for(int i=0;i<rows;i++)
{
    cout<<endl<<endl;
    for(int j=0;j<cols;j++)
    {
        cout<<matrix[i][j]<<" ";
        if(matrix[i][j]==0)
        {
            count++;
        }
    }
}
if(count>total/2)
{
cout<<endl<<"This is a Sparse Matrix";
sparse_flag=true;
}
else
cout<<endl<<"this is not a sparse matric";
}
void sparse::triplet()
{
if(sparse_flag==true)
{
   nonsparse=total-count;
    matrix2=new int*[nonsparse];
    for(int i=0;i<nonsparse;i++)
    {
        matrix2[i]=new int[3];
    }

    int a2=0;
    for(int i=0;i<rows;i++)
{

    for(int j=0;j<cols;j++)
    {
        cout<<endl;
      
        if(matrix[i][j]>0)
        {
            matrix2[a2][0]=i;
            matrix2[a2][1]=j;
            matrix2[a2][2]=matrix[i][j];
            a2++;
        }
    }
}
cout<<"Zero Elements"<<count<<endl;
cout<<"Non Zero Elements"<<nonsparse<<endl;
cout<<"=======SPARSE TRIPLET IS========"<<endl;
cout<<endl<<"Row"<<"  Column"<<"   Value"<<endl;
for(int i=0;i<nonsparse;i++)
{
    cout<<" "<<matrix2[i][0]<<"  "<<matrix2[i][1]<<"  "<<matrix2[i][2];
    cout<<endl;
}

}}
void sparse::search()
{
    int search1;
    bool flag=false;
    cout<<"enter value to search ";
    cin>>search1;
    for(int i=0;i<nonsparse;i++)
    {
     if(matrix2[i][2]==search1)
     {
        cout<<endl<<"found at "<<" row "<<matrix2[i][0]<<" Column"<<matrix2[i][1]<<endl;
        flag=true;
     }
    }
    if(flag==false)
    {
        cout<<"item not found";
    }


}
int main()
{
    sparse s1;
    s1.input();
    s1.check();
    s1.triplet();
    s1.search();
    return 0;
}

