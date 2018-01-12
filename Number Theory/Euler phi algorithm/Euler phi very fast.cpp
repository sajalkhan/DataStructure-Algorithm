#include<bits/stdc++.h>
using namespace std;
//#define max 2000100
//long long phi[max];
long long   phi(long long n)
{
    long long result=n;
    for(long i=2;i*i<=n;i++)
    {
        if(n%i==0)result-=result/i;
        while(n%i==0)n/=i;
    }
    if(n>1)result-=result/n;
    return result;
}
int main()
{
    int n;
    while(cin>>n)
    {
        printf("%d\n",phi(n));
    }
    return 0;
}
