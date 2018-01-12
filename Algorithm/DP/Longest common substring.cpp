#include<bits/stdc++.h>
using namespace std;
void lcs(string a,string b)
{
    int m=a.size();
    int n=b.size();
    int L[m+1][n+1];
//    vector<int>v[n+1];
//    for(int i=0; i<=m; i++)
//    {
//        for(int j=0; j<=n; j++)
//        {
//			v[i].push_back(0);
//        }
//    }
    int result=0;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
              L[i][j]=L[i-1][j-1]+1;
              result=max(result,L[i][j]);
//				v[i][j]=v[i-1][j-1]+1;
//				result=max(result,v[i][j]);
            }
            else
            {
                L[i][j]=0;
            }
        }
    }
    printf("%d\n",result);
}
int main()
{
    string a,b;
    while(getline(cin,a),getline(cin,b))
    {
        lcs(a,b);
    }
    return 0;
}
