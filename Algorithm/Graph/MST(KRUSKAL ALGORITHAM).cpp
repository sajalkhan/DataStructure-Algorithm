#include<bits/stdc++.h>
using namespace std;
struct node
{
    string u,v;
    int w;
    bool operator <(const node& p)const
    {
        return w<p.w;
    }
};
vector<node>graph;
map<string,string>join;
string find(string s)
{
    if(join[s]=="")return s;
    return join[s]=find(join[s]);
}
int mst(int n)
{
    join.clear();
    sort(graph.begin(),graph.end());
    int count=0,sum=0;
    for(int i=0;i<graph.size();i++)
    {
        string u=find(graph[i].u);
        string v=find(graph[i].v);
        if(u!=v)
        {
            join[u]=v;
            count++;
            sum+=graph[i].w;
            if(count==n-1)break;
        }
    }
    return sum;
}
int main()
{
    string u,v;
    int n,e,w;
    cin>>n>>e;
    node edge;
    getchar();
    graph.clear();
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        edge.u=u;
        edge.v=v;
        edge.w=w;
        graph.push_back(edge);
    }
    cout<<mst(n)<<endl;
    return 0;
}
/*
7 11
A B 7
A D 5
B C 8
D B 9
D E 15
B E 7
C E 5
D F 6
E F 8
F G 11
E G 9
*/
