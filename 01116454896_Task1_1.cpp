#include<iostream>
using namespace std;
int main()
{
    //cout<<"GRU";

    //[BONUS]
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=22;j++)
        {
            if(i==1)
                cout<<(((1<=j && j<=5)||(9<=j && j<=12)||j==17||j==22) ? '*' : ' ');
            if(i==2 || i==4)
                cout<<((j==1 || j==9 || j==13 || j==17 || j==22 || (i==4 && j ==5)) ? '*' : ' ');
            if(i==3)
                cout<<(((4<=j && j<=5)||(9<=j && j<=12)||j==1||j==17||j==22) ? '*' : ' ');
            if(i==5)
                cout<<(((1<=j && j<=5)||(17<=j && j<=22)||j==9||j==14) ? '*' : ' ');

        }
        cout<<'\n';
    }
    return 0;
}
