#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int a[10000]={0},b[10000]={0},c[10000]={0};
        int I=0,J=0;
        for(int i=s1.size()-1; i>=0; i--)a[i]=s1[I++]-'0';
        for(int i=s2.size()-1; i>=0; i--)b[i]=s2[J++]-'0';
        int M=max(s1.size(),s2.size());
        for(int i=0; i<M; i++)
        {
            int sum=a[i]+b[i];
            if(sum>9)
            {
            	c[i]=sum%10; 	//  [ c[i]=(18%10)=8 ]
            	a[i+1]+=1;  	//  [ a[1]=18; so a[1+1] means a[2]+=1; suppose a[2]=3, then a[2]=4 ]
            	if(i==M-1)M++;  //  [ add 9+9 then sum=18 so c[i]=sum%18; then c[0]=8, but we need 18 so we need 1 more loop.so we increment M++ ]
            }
            else c[i]=sum;
		}
		for(int i=M-1;i>=0;i--)cout<<c[i];
		cout<<endl;
    }
    return 0;
}
