#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
int node,edge,src,des;
vector<vi>graph;
bool ans,mark[100];
void DFS(int u)
{
    for(int i=0; i<graph[u].size(); i++)
    {
        int v=graph[u][i];
        if(!mark[v])continue;
        if(v==des)ans=true;
        mark[v]=false;
        DFS(v);
        mark[v]=true;
    }
}

int main()
{
    cout<<"Please enter node and edge"<<endl;
    while(~scanf("%d %d",&node,&edge))
    {
        graph.assign(node+5,vi());
        for(int i=0; i<node; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
        }
        cout<<"please enter source and destination:"<<endl;
        scanf("%d %d",&src,&des);
        ans=false;
        memset(mark,true,sizeof(mark));
        DFS(src);
        puts(ans?" YES":"NO");
    }
    return 0;
}
/*

3 4

1 2
2 3
3 4

1 4


3 4
1 2
2 3
3 4

1 5

*/
