#include <iostream>
using namespace std;

class mat
{
    public:
    int **matrix1;
    int rows,cols;
    int **matrix2;
    int **matrix3;
    void input();
    void print();
    void multiplier();
};

void mat::input()
{
    cout<<"Enter Dimensions of a matrix";
    cout<<"enter the amount of columns"<<endl;
    cin>>cols;
    cout<<"enter the amount of rows"<<endl;
    cin>>rows;
    matrix1=new int*[rows];
    matrix2=new int*[rows];
    matrix3 = new int*[rows];

    for(int i=0;i<rows;i++)
    {
    matrix1[i]=new int[cols];
    matrix2[i]=new int[cols];
    matrix3[i]=new int[cols];
    }
    cout<<"Matrix Created of"<<rows<<"*"<<cols<<endl;
    cout<<endl<<endl<<"=========Enter Values Matrix 1 =========";


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
      cout<<endl<<"Rows "<<i+1<<" Column "<<j+1<<endl;
      cin>>matrix1[i][j];
}}
 cout<<endl<<endl<<"=========Enter Values Matrix 2 =========";


    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
      cout<<endl<<"Rows "<<i+1<<" Column "<<j+1<<endl;
      cin>>matrix2[i][j];
}}}
void mat::print()
{
     system("cls");
     cout<<"======Matrix1======"<<endl;
     for(int i=0;i<rows;i++)
{
    cout<<endl<<endl;
    for(int j=0;j<cols;j++)
    {;
        cout<<matrix1[i][j]<<" ";
    }
}
cout<<endl<<"======Matrix2======"<<endl;
 for(int i=0;i<rows;i++)
{
    cout<<endl<<endl;
    for(int j=0;j<cols;j++)
    {
        cout<<matrix2[i][j]<<" ";
    }
}
}
void mat::multiplier(){
for (int i = 0; i < rows; i++)
    {
   for (int j = 0; j < cols; j++)
        {
            matrix3[i][j] = 0; 
            for (int k = 0; k < cols; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }}
        
        cout<<endl<<"======Resultant Matrix======"<<endl;
 for(int i=0;i<rows;i++)
{
    cout<<endl<<endl;
    for(int j=0;j<cols;j++)
    {
        cout<<matrix3[i][j]<<" ";
    }
}
}

int main()
{
    mat a1;
    a1.input();
    a1.print();
    a1.multiplier();
}

