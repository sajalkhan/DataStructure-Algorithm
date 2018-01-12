#include<bits/stdc++.h>
using namespace std;

#define mx 1000000
#define inf 2000000000
int a[mx],L[(mx/2)],R[(mx/2)],cnt;
void merge(int p,int q,int r)
{
    int LS=1,RS=1;
    for(int i=p; i<=q; i++)L[LS++]=a[i]; /// Left side
    L[LS]=inf;
    for(int i=q+1; i<=r; i++)R[RS++]=a[i]; /// Right side
    R[RS]=inf;
    int i=1,j=1;
    for(int k=p; k<=r; k++) /// merge L+R and sort...
    {
        if(L[i]>R[j])
        {
            cnt+=LS-i; /// count how many swap are there
            a[k]=R[j];
            j++;
        }
        else
        {
            a[k]=L[i];
            i++;
        }
    }
}
void mergesort(int p,int r)
{
    if(p<r)
    {
        int q;
        q=(p+r)/2;
        mergesort(p,q);
        mergesort(q+1,r);
        merge(p,q,r);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        cnt=0;
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        mergesort(1,n);
        for(int i=1; i<=n; i++)cout<<a[i]<<" ";
        cout<<endl;
        cout<<cnt<<endl;
    }
    return 0;
}
