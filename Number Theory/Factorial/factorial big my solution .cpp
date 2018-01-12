/*
	Md.soharub hossen sajal
	Daffodil international university
	program: Find factorial of a bing number
*/

#include<bits/stdc++.h>
using namespace std;
#define max 100000
string factorial(int n)
{
    int count=0;
    string s1,s2;
    while(n!=0)
    {
        if(n==1)return s1;
        stringstream ss;
        string num;
        ss<<n;
        ss>>num;
        if(!count)
        {
            s1=num;
            count=1;
            n--;
            continue;
        }
        if(count)s2=num,n--;
        int a[max]= {0},b[max]= {0},c[max]= {0},d[max]= {0},e[max]= {0};
        int I=0,J=0;
        for(int i=s1.size()-1; i>=0; i--)a[I++]=s1[i]-'0';
        for(int i=s2.size()-1; i>=0; i--)b[J++]=s2[i]-'0';
        int Ma,Mi;
        if(s1.size()>=s2.size())
        {
            Ma=s1.size();
            Mi=s2.size();
            for(int i=0; i<s1.size(); i++)d[i]=a[i];
            for(int i=0; i<s2.size(); i++)e[i]=b[i];
        }
        else if(s1.size()<s2.size())
        {
            Mi=s1.size();
            Ma=s2.size();
            for(int i=0; i<s1.size(); i++)e[i]=a[i];
            for(int i=0; i<s2.size(); i++)d[i]=b[i];
        }
        int carry=0,count=0;
        for(int i=0; i<Mi; i++)
        {
            for(int j=0; j<Ma; j++)
            {
                int sum=d[j]*e[i]+carry;
                if((c[i+j]+sum)>9)
                {
                    int cr=c[i+j]+sum;
                    c[i+j]=(c[i+j]+sum)%10;
                    if(!i)carry=sum/10;
                    else carry=(cr)/10;
                    if(j==Ma-1)Ma++;
                }
                else
                {
                    c[i+j]=c[i+j]+sum;
                    carry=sum/10;
                }
                if(i==Mi-1) count++;
            }
        }
        s1.clear();
        for(int i=count+Mi-2; i>=0; i--)
        {
            s1+=c[i]+'0';
        }
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        printf("%d!\n",n);
        cout<<factorial(n)<<endl;
    }
    return 0;
}
