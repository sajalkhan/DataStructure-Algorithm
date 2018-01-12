#include<bits/stdc++.h>
using namespace std;
#define max 10000
set<int>s;
set<int>::iterator it;
vector<int>G[max];
void bfs(int n,int src)
{
    queue<int>q;
    q.push(src);
    int visited[100]= {0},level[100];
    int parent[100]={0};
    visited[src]=1;
    level[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!visited[v])
            {
                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    for(int i=src; i<=n; i++)cout<<src<<" to "<<i<<" distance "<<level[i]<<" and parent node is "<<parent[i]<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        s.insert(x);
        G[x].push_back(y);
    }
    it=s.begin();
    bfs(n,*it);
    return 0;
}
