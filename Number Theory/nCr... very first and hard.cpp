#include<bits/stdc++.h>
using namespace std;
/**
    n!
..........
 K!(n-k)!

**/
long long factorial(long long a)
{
    long long result=1;
    for(int i=1; i<=a; i++)
    {
        result=result*i;
    }
    return result;
}
long long NCR(long long n,long long k)
{
//    return =(factorial(n))/(factorial(k)*factorial(n-k));
    k=min(k,n-k);
    long result=1;
    for(int i=1;i<=k;i++)
    {
        result=result*(n-k+i)/i;
    }
    return result;
}
int main()
{
    long long n,k;
    while(scanf("%lld %lld",&n,&k)!=EOF && n)
    {
        cout<<NCR(n,k)<<endl;
    }
    return 0;
}
