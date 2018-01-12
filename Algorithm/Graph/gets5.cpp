#include <bits/stdtr1c++.h>

#define MAXN 100010
#define INF 1000000010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> Pair;

set <Pair> S;
vector <int> edge_weight[MAXN];
vector <int> adjacency_list[MAXN];
int number_of_nodes, dis[MAXN];

int dijkstra(int source, int destination){
    S.clear();
    for (int i = 1; i <= number_of_nodes; i++) dis[i] = INF;

    dis[source] = 0;
    S.insert(Pair( dis[source], source ));

    while (!S.empty()){
        Pair current_state = *(S.begin());
        S.erase(current_state);

        int current_vertex = current_state.second;
        for (int j = 0; j < adjacency_list[ current_vertex ].size(); j++){
            int current_neighbour = adjacency_list[current_vertex][j];
            int path_cost_to_neighbour = edge_weight[current_vertex][j];
            if (dis[current_neighbour] > dis[current_vertex] + path_cost_to_neighbour){
                dis[current_neighbour] = dis[current_vertex] + path_cost_to_neighbour;
                S.insert( Pair(dis[current_neighbour], current_neighbour) );
            }
        }
    }

    return dis[destination];
}

int main(){
    int number_of_edge, source, destination, i, u, v, w;

    cin >> number_of_nodes >> number_of_edge;
    while (number_of_edge--){
        cin >> u >> v >> w; /// Undirected edge from u to v with weight w
        adjacency_list[u].push_back(v), edge_weight[u].push_back(v);
        adjacency_list[v].push_back(u), edge_weight[v].push_back(u);
    }

    cin >> source >> destination;
    cout << dijkstra(source, destination);
    return 0;
}
