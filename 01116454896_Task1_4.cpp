#include<iostream>
using namespace std;
float weightedAvg(float measur1, float measur2, float acc1, float acc2)
{
    return ((measur1*acc1 + measur2*acc2) / (acc1 + acc2));
}
int main()
{
    const int N =10;
    const float mpu_acc = 0.78;
    const float bno_acc = 0.92;
    float mpu6050[] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    float res[N];
    for(int i=0;i<N;i++)
        res[i]=weightedAvg(mpu6050[i], bno55[i], mpu_acc, bno_acc);
    for(int i=0;i<N;i++)
    {
        if(i) cout<<", ";
        cout<<res[i];
    }

    return 0;
}
