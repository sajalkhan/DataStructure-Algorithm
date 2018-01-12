#include<bits/stdc++.h>
using namespace std;

#define mx 100000
#define ll unsigned long long
ll a[mx];
struct node
{
    ll prop,sum;
}tree[mx*4];
void Make_tree(int node,int start,int End)
{
    if(start==End)
    {
        tree[node].sum=a[start];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+End)>>1;
    Make_tree(left,start,mid);
    Make_tree(right,mid+1,End);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
int query(int node,int start,int End,int i,int j,int carry=0)
{
    if(i>End || j<start)return 0;
    if(start>=i && End<=j)return tree[node].sum+carry*(End-start+1);
    int left=node*2;
    int right=left+1;
    int mid=(start+End)>>1;
    int q1=query(left,start,mid,i,j,carry+tree[node].prop);
    int q2=query(right,mid+1,End,i,j,carry+tree[node].prop);
    return q1+q2;
}
void update(int node,int start,int End,int i,int j,ll x)
{
    if(i>End || j<start)return;
    if(start>=i && End<=j)
    {
        tree[node].sum+=(End-start+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+End)>>1;
    update(left,start,mid,i,j,x);
    update(right,mid+1,End,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(End-start+1)*tree[node].prop;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%llu",&a[i]);
    Make_tree(1,1,n);
    update(1,1,n,1,3,10);
    cout<<query(1,1,n,1,5)<<endl;
    return 0;
}
