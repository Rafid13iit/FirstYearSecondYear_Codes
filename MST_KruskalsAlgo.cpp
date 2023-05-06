#include <bits/stdc++.h>
using namespace std;
#define MX 100

typedef long long int ll;
typedef unsigned long long int llu;

struct EdgesAndWeight{
    ll u, v, weight;
} edgesAndweight[MX];

ll parent[MX];
ll setRank[MX] = {0};


//Disjoint Set starts
void makeSet(int x)
{
    parent[x] = x;
}

ll findParent (ll x)
{
    if (x != parent[x]){
        return parent[x] = findParent(parent[x]);
    }
    else{
        return x;
    }
}

void makeUnion (ll u, ll v)
{
    ll uP = findParent(u);
    ll vP = findParent(v);

    if (uP == vP) return ;

    if (setRank[uP] < setRank[vP]){
        parent[uP] = vP;
    }
    else if (setRank[uP] > setRank[vP]){
        parent[vP] = uP;
    }
    else {
        parent[vP] = uP;
        setRank[uP]++;
    }

}
//Disjoint Set ends


ll kruskal (ll nodes, ll edges)
{
    for(ll i = 0; i < nodes; i++){
        makeSet(i);
    }

    ll answer = 0;

    for(ll i = 0; i < edges; i++)
    {
        ll u = edgesAndweight[i].u;
        ll v = edgesAndweight[i].v;
        ll w = edgesAndweight[i].weight;

        if(findParent(u) != findParent(v))
        {
            makeUnion(u, v);

            cout << "u -> v : " << u << "->" << v << ", weight = " << w << endl;

            answer += w;
        }
        //else nothing to do, just skip the edge pair
    }

    return answer;
}

int main ()
{
    ll nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    ll adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph
    for (ll i = 0; i < nodes; i++) {
        for (ll j = 0; j < nodes; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    cout << "Enter edges (u v) and it's weight:\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgesAndweight[i].u >> edgesAndweight[i].v >> edgesAndweight[i].weight;
        adj_matrix[edgesAndweight[i].u][edgesAndweight[i].v] = 1;
        adj_matrix[edgesAndweight[i].v][edgesAndweight[i].u] = 1; // Comment this line for directed graph
    }

    //sorting by weight
    struct EdgesAndWeight temp;

    for (ll i = 0; i < edges; i++){
        for (ll j = i + 1; j < edges; j++){
            if (edgesAndweight[i].weight > edgesAndweight[j].weight){

                temp = edgesAndweight[i];
                edgesAndweight[i] = edgesAndweight[j];
                edgesAndweight[j] = temp;
            }
        }
    }

    // for (int i = 0; i < edges; i++) {
    //     cout << edgesAndweight[i].weight << " " << edgesAndweight[i].u << " " << edgesAndweight[i].v << endl;
    // }
    
    cout << "MST cost is : " << kruskal(nodes, edges) << endl;

    return 0;
}

/*
9
14
0 1 4
1 2 8
2 3 7 
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
0 7 8
1 7 11
2 8 2
6 8 6
2 5 4
3 5 14
*/