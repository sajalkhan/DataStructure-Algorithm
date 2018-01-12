#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int a[mx];
int tree[mx*3];
void Make_tree(int node,int start,int End)
{
    if(start==End)
    {
        tree[node]=a[start];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    Make_tree(left,start,mid);
    Make_tree(right,mid+1,End);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int start,int End,int i,int j)
{
    if(i>End || j<start)return 0;
    if(start>=i && End<=j)return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    int p1=query(left,start,mid,i,j);
    int p2=query(right,mid+1,End,i,j);
    return p1+p2;
}
void update(int node,int start,int End,int i,int value)
{
    if(i>End || i<start)return;
    if(start>=i && End<=i)
    {
        tree[node]+=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+End)/2;
    update(left,start,mid,i,value);
    update(right,mid+1,End,i,value);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Make_tree(1,1,n);
    update(1,1,n,5,5);
    printf("%d\n",query(1,1,n,3,6));
    return 0;
}
