#include<bits/stdc++.h>
using namespace std;
#define max 9999999
vector<int>prime;
bool isprime[max];
void sieve()
{
    for(int i=3; i*i<=max; i+=2)
    {
        if(!isprime[i])for(int j=i*i; j<=max; j+=i*2)isprime[j]=true;
    }
    prime.push_back(2);
    for(int i=3;i<=max;i+=2)if(!isprime[i])prime.push_back(i);
}
void prime_factor(long long n)
{
    for(long  i=0;prime[i]*prime[i]<=n;i++)
    {
        while(n%prime[i]==0)
        {
            cout<<prime[i]<<" ";
            n/=prime[i];
        }
    }
    if(n>1)cout<<n<<endl;
}
int main()
{
    sieve();
    long long n;
    while(cin>>n)
    {
        prime_factor(n);
    }
    return 0;
}
