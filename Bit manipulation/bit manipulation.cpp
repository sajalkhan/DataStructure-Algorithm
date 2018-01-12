#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="ABC";
    int n=s.size();
    /*
        1<<n
        so 1=00000001
        now left shift n,n=3;
        so 1<<n = 00001000
        means i<8
    */
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            /*
                i&(1<<j)
                suppose i=1,i=0001
                1<<j now j=0;
                1<<j = 0001
                so 0001 && 0001 = 1
                now j=1
                1<<j means 1=(0001<<1)=0010
                now 0001 && 0010 = 0
            */
            if(i&(1<<j))
            {
                cout<<s[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
