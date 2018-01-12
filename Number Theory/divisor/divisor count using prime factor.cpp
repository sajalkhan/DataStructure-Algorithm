#include<bits/stdc++.h>
using namespace std;
int prime[1001];
void primefactor(long long n)
{
    int j=0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                prime[j++]=i;
                n/=i;
            }
        }
    }
    if(n>1)prime[j++]=n;
}
long long  divisor(long long  n)
{
    primefactor(n);
    long long  div=1;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int count=1;
            while(n%prime[i]==0)
            {
                count++;
                n/=prime[i];
            }
            div*=count;
        }
    }
    if(n>1)div*=2;
    cout<<div<<endl;
}
int main()
{
    long long  n;
    while(cin>>n)
    {
        printf("%d total divisor ",n);
        divisor(n);
    }
    return 0;
}
