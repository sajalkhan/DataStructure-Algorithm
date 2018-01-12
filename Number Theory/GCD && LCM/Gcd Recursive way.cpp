#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) // recursive big
{
    if(b==0) return a;
    else gcd(b,a%b);
}
int Gcd(int a,int b) // small
{
    return b==0 ? a : Gcd(b,a%b);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("GCD of %d and %d = %d\n",a,b,Gcd(a,b));
    return 0;
}
