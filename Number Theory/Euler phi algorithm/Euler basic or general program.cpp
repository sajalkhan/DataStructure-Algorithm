#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    while(cin>>n)
    {
        int phi=0;
        for(int i=1;i<=n;i++)if(gcd(i,n)==1)phi++;
        printf("%d\n",phi);
    }
    return 0;
}
