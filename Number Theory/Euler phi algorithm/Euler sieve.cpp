#include<bits/stdc++.h>
using namespace std;
#define max 1000000
int phi[max];
void euler_phi()
{
    for(long i=1;i<max;i++)phi[i]=i;
    for(long i=2;i<max;i++)
    {
        if(phi[i]==i)
        {
            for(int k=i;k<max;k+=i)
            {
                phi[k]-=phi[k]/i;
            }
        }
    }
}
int main()
{
    euler_phi();
    long n;
    while(cin>>n)
    {
        printf("%ld\n",phi[n]);
    }
    return 0;
}
