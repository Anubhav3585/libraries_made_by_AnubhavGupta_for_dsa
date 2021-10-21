#include<iostream>
using namespace std;

int vector(int i,int j,int size)
{
    return i;
}

int main()
{
    int r=3;
    int a[r][r]={{1,0,0},{0,4,0},{0,0,8}};

    int array[10];

    for(int d=0;d<3;++d)
    {
        for(int v=0;v<3;++v)
        {
            if(d==v)
            {
                array[vector(d,v,3)]=a[d][v];
            }
        }
    }

    for(int c=0;c<3;++c)
    {
        cout<<array[c]<<" ";
    }
    return 0;
}