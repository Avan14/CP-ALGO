#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    bool cycle_for_undirected(int src, int numCou, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push(make_pair(src, -1));
        vector<int> vis(numCou + 1, false);
        vis[src] = true;
        while (!q.empty()) {
            auto [v, p] = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (!vis[u]) {
                    q.push(make_pair(u, v));
                    vis[u] = true;
                } else if (p != u) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs_directed(int node, vector<int> adj[], vector<int>& Vis,
                      vector<int>& PathVis) {
        Vis[node] = 1;
        PathVis[node] = 1;
        for (auto u : adj[node]) {
            if (!Vis[u]) {
                if (dfs_directed(u, adj, Vis, PathVis)) {
                    return true;
                }
            } else if (Vis[u] == 1 && PathVis[u] == 1) {
                return true;
            }
        }
        PathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<int> grid[2001];
        vector<int> PreREQ(numCourses, 0);
        queue<int> q;
        int cnt = numCourses;
        for (int i = 0; i < n; i++) {
            PreREQ[pre[i][0]]++;
            grid[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> Vis(numCourses, 0), PathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!Vis[i]) {
                if (dfs_directed(i, grid, Vis, PathVis)) {
                    return false; // cycle exists → can’t finish
                }
            }
        }
        // return cycle_for_undirected(1, numCourses, grid);

        // for (int u = 0; u < numCourses; u++) {
        //     if (PreREQ[u] == 0)
        //         q.push(u);
        // }
        // while (!q.empty()) {
        //     int u = q.front();
        //     q.pop();
        //     cnt--;
        //     for (int v : grid[u]) {
        //         PreREQ[v]--;
        //         if (PreREQ[v] == 0)
        //             q.push(v);
        //     }
        // }
        return true;
    }
};
