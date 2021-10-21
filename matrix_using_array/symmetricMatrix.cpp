#include<iostream>
using namespace std;

int vector(int i,int j,int size)
{
    if(i>=j)
    return (i*(i+1)/2)+j;

    else
    return (j*(j+1)/2)+i;
}
int main()
{
    int array[3][3]={{1,2,3},{2,4,5},{3,5,6}};

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

    for(int d=0;d<3;++d)
    {
        for(int c=0;c<3;++c)
        {
            cout<<array1[vector(d,c,3)]<< " ";
        }

        cout<<endl;
    }
    return 0;
}