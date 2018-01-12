#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cctype>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;
#define mx 1000007
#define pb push_back
#define clr(a) memset(a, 0, sizeof(a))
#define clrc(b) memset(b, ' ', sizeof(b))
#define sf scanf
#define pf printf

typedef vector< int > vi;
typedef long long int ll;
vector< ll > prime,fc,divi,tz;

int memo[mx];
bool mark[mx];
bool seg[mx];
void sieve();

void sieve()
{
    mark[0]=true;
    mark[1]=true;
    for(int i = 4; i<=mx; i += 2)mark[i] = true;

    for(int i=3; i*i<mx; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=mx; j+=2*i)
            {
                mark[j]=true;
            }
        }
    }

    prime.pb(2);

    for(int k=3; k<mx; k+=2)
    {
        if(!mark[k])
        {
            prime.pb(k);
        }
    }
}

int main()
{
    sieve();
    ll i, j, k;
    ll start,a,b,l,l1,u,d1,d2,c1,c2,e,s;
    while(cin>>a>>b)
    {
        ll l = a;
        vector<ll>segmented;
        memset(seg,false,mx);

        for( i = 0; i<=b; i++)
        {
            if(prime[i]*prime[i]>b)break;
            if(a%prime[i]==0) start = a;

            else
            {
                start = a / prime[i];
                start =start*prime[i]+prime[i];
            }

            for( j = start ; j<= b; j +=prime[i])
            {
                seg[j-l] = true;
            }
        }
        for( i = a; i<=b; i++)
        {
            if(i<=mx)
            {
                if(!mark[i])segmented.pb(i);
                continue;
            }
            if(!seg[i-l])segmented.pb(i);
        }
        for(int i=0;i<segmented.size();i++)cout<<segmented[i]<<" ";
        cout<<endl;
    }
    return 0;
}

