#include<bits/stdc++.h>
using namespace std;
#define max 100000
bool isprime[max];
int prime[max];
void sive()
{
    for(int i=3; i*i<=max; i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i; j<=max; j+=i)
                isprime[j]=true;
        }
    }
    int k=0;
    prime[k++]=2;
    for(int i=3; i<=max; i+=2)
    {
        if(!isprime[i])prime[k++]=i;
    }
}
int main()
{
    sive();
    long long n;
    while(cin>>n)
	{
		int t=0;
		for(int i=0; i<n; i++)if(prime[i]==n)t=1,cout<<n<<" is a prime number."<<endl;
		if(!t)cout<<n<<" is not a prime number."<<endl;
	}
    return 0;
}
