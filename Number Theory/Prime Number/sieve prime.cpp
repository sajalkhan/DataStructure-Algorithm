#include<bits/stdc++.h>
using namespace std;
#define max 9999999
int a[max];
void sieve()
{
    int sq=sqrt(max);
    a[0]=1;
    a[1]=1;
    for(int i=4; i<max; i+=2)a[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(a[i]==0)
        {
            for(int j=i*i; j<=max; j+=i)a[j]=1;
        }
    }
}
int main()
{
    int n;
    sieve();
    cout<<"Enter any number:";
    cin>>n;
    if(a[n]==0)printf("Prime number\n");
    else printf("Not Prime\n");
    return 0;
}
