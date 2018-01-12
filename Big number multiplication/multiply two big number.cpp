/*
	Md.soharub hossen sajal
	Daffodil international university
	program: Multiplication of two big integer number
*/

#include<bits/stdc++.h>
using namespace std;
#define max 100000
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        string s3,s4;
        s3=s1;
        s4=s2;
        stringstream s5,s6;
        int n,m;
        s5<<s3;
        s5>>n;
        s6<<s4;
        s6>>m;
        if(n==0 || m==0)
        {
            cout<<s1<<" * "<<s2<<" = "<<"0"<<endl;
            continue;
        }
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
        int I2=0;
        cout<<s1<<" * "<<s2<<" = ";
        for(int i=count+Mi-2; i>=0; i--)
        {
        	if(!I2 && !c[i])continue;
            else I2=1,cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
