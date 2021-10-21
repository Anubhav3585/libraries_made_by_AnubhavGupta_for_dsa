#include<iostream>
using namespace std;

int vector(int i,int j,int size)
{
    return (i*(i+1)/2)+j;
}

int main()
{
    int array[3][3]={{1,0,0},{2,3,0},{4,5,6}};

    int array1[9];

    for(int x=0;x<3;++x)
    {
        for(int c=0;c<3;++c)
        {
            if(c<=x)
            {
                array1[vector(x,c,3)]=array[x][c];
            }
        }
    }

    for(int s=0;s<3*(3+1)/2;s++)
    {
        cout<<array1[s]<<" ";
    }
    cout<<endl;
    return 0;
}