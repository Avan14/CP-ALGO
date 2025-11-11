#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int prims(int n, vector<vector<int>> &edges)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<vector<pair<int,int>>> adj(n);
    for( auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool> visited(n, false);
    pq.push({0, 0});

    int mstVal = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int wt = top.first;
        int u = top.second;
        
        if (visited[u]) continue;
        visited[u] = true;
        mstVal += wt;
        for (auto it : adj[u])
        {
            int v = it.first;
            int edgeWt = it.second;
            if (!visited[v])
            {
                pq.push({edgeWt, v});
            }
        }
    }
    return mstVal;
}


void kruskal(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    DSU dsu(n);
    int mstVal = 0;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.unionSets(u, v);
            mstVal += wt;
        }
    }

    cout << "MST value using Kruskal's: " << mstVal << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    // test case 
    vector<vector<int>> edges = {
        {0, 1, 12},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 8},
        {2, 3, 10}};

    int n = 4;
    cout << prims(n, edges) << "\n";

    kruskal(n, edges);

    return 0;
}