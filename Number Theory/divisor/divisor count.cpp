#include<bits/stdc++.h>
using namespace std;
#define max 10000
int main()
{
    long long n,a[max],j=0,sum=0;
    cin>>n;
    long long k=sqrt(n);
    for(int i=1;i<=k;i++)
    {
        if(n%i==0)
        {
            if(n/i!=i)
            {
                a[j++]=i;
                a[j++]=n/i;
                sum+=i;
                sum+=n/i;
            }
            else a[j++]=i,sum+=i;
        }
    }
    sort(a,a+j);
    for(int i=0;i<j;i++)
    {
        if(!i)printf("%lld",a[i]);
        if(i)printf(",%lld",a[i]);
    }
    cout<<endl<<endl<<"TOTAL SUM IS : "<<sum<<endl;
    return 0;
}
