/*
    Author   : Rajdip Saha
    Language : C++
*/

#include <bits/stdc++.h>

#define row 1000
#define col 1000
#define MAX 100000
#define MOD 1000000007
#define PI 2*acos(0.0)

typedef struct node node;
typedef long long int ll;
typedef unsigned long long int llu;

using namespace std;

bool isprime[MAX];

vector < int > prime;

void sieve()
{
    int sq=sqrt(MAX);
    for(int i=3;i<=sq;i+=2){
        if(!isprime[i]){
            for(int j=i*i;j<=MAX;j+=i*2){
                isprime[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=MAX;i+=2){
        if(!isprime[i])prime.push_back(i);
    }
}

int DivCount(int n)
{
    int div=1;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            int cnt=1;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
            div*=cnt;
        }
    }
    if(n>1)div*=2;
    return div;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	sieve();
    int n,cases=1;
    while(~scanf("%d",&n)){
        printf("Case %d: %d\n",cases++,DivCount(n));
    }
	return 0;
}
