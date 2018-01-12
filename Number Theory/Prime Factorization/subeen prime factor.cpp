/*
	sajal khan
	prime factor
*/
#include<bits/stdc++.h>
using namespace std;
#define max 10000
int main()
{
    int n,a[max];
    map<int,int>mp;
    while(scanf("%d",&n))
    {
    	if(n<2)break;
    	mp.clear();
        int m=n,j=0;
        for(int i=2; i<=n/i; i++)
        {
            while(n%i==0)
            {
                n/=i;
                a[j++]=i;
                mp[i]++;
            }
        }
        if(n>1)a[j++]=n,mp[n]++;
        int count=0;
        printf("%d = ",m);
        int b=0;
        for(int i=0; i<j; i++)
        {
            if(!b)b=a[i],cout<<a[i]<<"^"<<mp[a[i]];
			if(b!=a[i])b=a[i],cout<<" * "<<a[i]<<"^"<<mp[a[i]];
        }
        printf("\n");
    }
    return 0;
}
