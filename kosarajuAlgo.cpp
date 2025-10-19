// Position this line where user code will be pasted.
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void dfs1(int v, stack<int> &stk, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[v] = true;

        for (auto u : adj[v])
        {
            if (!vis[u])
            {
                dfs1(u, stk, vis, adj);
            }
        }

        stk.push(v);
    }

    void dfs2(int v, vector<bool> &vis, vector<vector<int>> &revAdj)
    {
        vis[v] = true;

        for (auto u : revAdj[v])
        {
            if (!vis[u])
            {
                dfs2(u, vis, revAdj);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs1(i, stk, vis, adj);
            }
        }

        //
        vector<vector<int>> revAdj;
        for (int v = 0; v < n; v++)
        {
            for (int u : adj[v])
            {
                revAdj[u].push_back(v);
            }
        }
        vis.assign(n, false);
        int sccCnt = 0;
        while (!stk.empty())
        {
            int v = stk.top();
            stk.pop();

            if (!vis[v])
            {
                dfs2(v, vis, revAdj);
                sccCnt++;
            }
        }

        return sccCnt;
    }
};