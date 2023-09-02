#include<iostream>
#include <time.h>
using namespace std;
void delay(int sec) //[BONUS]
{
    int ms = 1000 * sec;
    clock_t st = clock();
    while(clock() < st + ms);
}
int main()
{
    int num;
    cin>>num;
    for(int i=num;i>0;i--)
    {
        cout<<i<<'\n';
        delay(1);
    }
    cout<<"Blast off to the moon!";
    return 0;
}
