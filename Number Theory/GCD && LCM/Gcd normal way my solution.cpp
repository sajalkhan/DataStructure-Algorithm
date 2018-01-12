#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	while(b)b^=a^=b^=a%=b;
	return a;
}
int main()
{
    int a,b,gcd;
    cin>>a>>b;
    while(a!=0)
    {
        if(a<b)
        {
            int c=b;
            b=a;
            a=c;
        }
        gcd=b;
        a=a%b;
    }
    cout<<gcd<<endl;
    return 0;
}
