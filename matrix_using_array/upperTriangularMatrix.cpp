#include<iostream>
using namespace std;

int vector(int i,int j,int size)
{
    return j+i*(size-(float)i/2-(float)1/2); 
}

int main()
{
    int array[3][3]={{1,2,3},{0,4,5},{0,0,6}};

    int a1[9];

    for(int c=0;c<3;++c)
    {
        for(int a=0;a<3;++a)
        {
            if(a>=c)
            {
                a1[vector(c,a,3)]=array[c][a];
            }
        }
    }

    for(int f=0;f<6;++f)
    {
        cout<<a1[f]<<" ";
    }
    cout<<endl;
    return 0;
}