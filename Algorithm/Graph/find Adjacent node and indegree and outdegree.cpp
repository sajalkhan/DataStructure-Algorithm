#include<bits/stdc++.h>
using namespace std;
#define max 10000
set<int>v;
set<int>::iterator it;
vector<int>edges[max];
map<int,int>indegree;
map<int,int>outdegree;
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        v.insert(x);
        edges[x].push_back(y);
    }
    cout<<endl<<"Adjacency list:"<<endl<<endl;
    for(it=v.begin();it!=v.end();it++)
    {
        for(int j=0;j<edges[*it].size();j++)
        {
            indegree[edges[*it][j]]++;
            outdegree[*it]++;
            if(!j)cout<<*it<<"--> ";
            if(j)printf(",");
            cout<<edges[*it][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<"Indegree  of "<<*it<<" is "<<"<--  "<<indegree[*it]<<endl;
        cout<<"Outdegree of "<<*it<<" is "<<"-->  "<<outdegree[*it]<<endl;
        cout<<endl;
    }
    return 0;
}
/*

6 8
1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
6 8
1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
*/
