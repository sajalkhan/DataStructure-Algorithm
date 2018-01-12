#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int LCM(int a,int b)
{
    return (b*a/(gcd(a,b)));
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<LCM(a,b)<<endl;
}
