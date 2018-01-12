#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int MST(int n );
int find_set(int r);

struct eage{

    int u , v , w;
    bool operator < (const eage& t) const { return w < t.w; }

};

vector < eage > ve;
int dis_set[5000];

int main()
{
    int a , b, x, y , z;
    eage temp;
    while ( scanf("%d %d", &a , &b) && (a || b) )
    {
        while(b--)
        {
            scanf("%d %d %d", &x , &y , &z);
            temp.u = x;
            temp.v = y;
            temp.w = z;
            ve.push_back(temp);
        }
        printf("%d\n", MST(a));
    }
    return 0;
}


int MST(int n )
{
    for(int i = 0 ; i < n ; ++i) dis_set[i] = i;
    sort(ve.begin() , ve.end());
    int sum = 0; int get = 0;
    int len = ve.size();
    for(int i = 0 ; i < len ; ++i)
    {
        int x = find_set(ve[i].u);
        int y = find_set(ve[i].v);
        if(x != y)
        {
            printf("[%d %d] = %d\n", ve[i].u , ve[i].v , ve[i].w);
            ++get;
            dis_set[x] = y;
            sum = sum + ve[i].w;
            if(get == n - 1) i = len;
        }
    }
    return sum;
}

int find_set(int r)
{
    if(dis_set[r] == r) return r;
    return dis_set[r]=find_set(dis_set[r]);
}

