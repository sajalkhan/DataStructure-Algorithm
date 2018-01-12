#include<bits/stdc++.h>
using namespace std;
#define max 2000
bool isprime[max];
int prime[max];
void sieve()
{
    for(int i=3; i<=sqrt(max); i+=2)
    {
        if(isprime[i]==false)
        {
            for(int j=i*i; j<=max; j+=i*2)
            {
                isprime[j]=true;
            }
        }
    }
    int k=0;
    prime[k++]=2;
    for(int i=3; i<=max; i+=2)
    {
        if(isprime[i]==false)
        {
            prime[k++]=i;
        }
    }
    int count=0;
    for(int i=0; i<k; i++)
    {
        printf("%d ",prime[i]);
    }
}
int main()
{
    sieve();
    return 0;
}
