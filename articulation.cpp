#include <iostream>
#include <vector>
using namespace std;

class Solution
{

private:
    int timer = 0;

public:
    void dfs(int u, int parent, vector<bool> &vis, vector<int> &dis, vector<int> &low_dis, vector<vector<int>> &adj, vector<int> &mark)
    {
        vis[u] = true;
        dis[u] = low_dis[u] = timer++;
        int childcnt = 0;
        for (int v : adj[u])
        {
            if (v == parent)
            {
                continue;
            }
            if (!vis[v])
            {
                dfs(v, u, vis, dis, low_dis, adj, mark);
                low_dis[u] = min(low_dis[u], low_dis[v]);

                if (low_dis[v] >= dis[u] && parent != -1)
                {
                    mark[u] = true;
                }
            }
            else
            {
                low_dis[u] = min(low_dis[u], dis[v]);
            }
        }
        if (parent == -1 && childcnt > 1)
        {
            mark[u] = true;
        }
    }
    vector<int> articulationPoints(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &con : connections)
        {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }

        vector<bool> vis(n, false);
        vector<int> dis(n, -1), low_dis(n, -1);
        vector<int> mark(n, false);

        for (int u = 0; u < n; u++)
        {
            if (!vis[u])
            {
                dfs(u, -1, vis, dis, low_dis, adj, mark);
            }
        }

        vector<int> ArtPoints;
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
            {
                ArtPoints.push_back(i);
            }
        }
        return ArtPoints;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}