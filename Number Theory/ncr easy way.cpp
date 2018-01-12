/**
    n!
..........
 K!(n-k)!

**/
#include<bits/stdc++.h>
using namespace std;
int main()
{


    long long int n,k,a,b,i,d;
    while(scanf("%lld %lld",&n,&k) && n)
    {
        a=1;
//        if(k>n/2)
//		{
//			k=k-n; // you have to use this condition to reduce time limit...
//		}
        for(i=0; i<k; i++)
        {
            a=a*(n-i)/(1+i);
        }
        printf("%lld\n",a);
    }

    return 0;
}
