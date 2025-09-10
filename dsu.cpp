#include <iostream>
#include < vector>
#include <algorithm>
#include <queue>
using namespace std;

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool union_(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
        {
            return false;
        }
        if (size[px] > size[py])
        {
            parent[py] = px;
            size[px] += size[py];
        }
        else
        {
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int prims(vector<pair<int, int>> adj[], int n)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n, 0);
    int mst = 0;
    pq.push({0, {0, -1}});
    while (!pq.empty())
    {
        auto [wt, edge] = pq.top();
        pq.pop();
        int node = edge.first;
        int parent = edge.second;
        if (vis[node])
            continue;
        vis[node] = 1;
        mst += wt;
        for (auto [v, w] : adj[node])
        {
            if (!vis[v])
            {
                pq.push({w, {v, node}});
            }
        }
    }
    return mst;
}

int kruskals(vector<pair<int, pair<int, int>>> adj, int n)
{
    DSU ds(n);
    sort(adj.begin(), adj.end());
    int cost = 0;
    for (auto it : adj)
    {
        int u = it.second.first, v = it.second.second, w = it.first;
        if (ds.union_(u, v))
        {
            cost += w;
        }
    }
    return cost;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}