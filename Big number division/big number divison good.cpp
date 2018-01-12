#include<bits/stdc++.h>
using namespace std;
int main()
{
    string num,result;
    long long d,mod=0,carry;
    cin>>num>>d;
    int ln=num.size();
    for(int i=0;i<ln;i++)
    {
        mod=mod*10+num[i]-'0';
        if(mod>=d)result+=(mod/d)+'0';
        if(mod!=0)carry=1;
        mod%=d;
        if(!mod && !carry)result+="0";
        carry=0;
    }
    cout<<result<<endl;
    return 0;
}
