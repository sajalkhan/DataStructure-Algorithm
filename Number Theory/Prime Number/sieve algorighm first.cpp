#include<bits/stdc++.h>
using namespace std;
#define maxi 9999999
int prime[maxi];
void sieve(long max)
{
    for(long long  i=3;i*i<=max;i+=2)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=max;j+=(2*i))prime[j]=true;
        }
    }
    int k=0;
    prime[k++]=2;
    for(int i=3;i<=max;i+=2)
    {
        if(!prime[i])prime[k++]=i;
    }
    for(int i=0;i<k;i++)printf("%d ",prime[i]);
}
int main()
{
    long n;
    cin>>n;
    sieve(n);
    return 0;
}
