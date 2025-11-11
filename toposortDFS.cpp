#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &result) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, vis, adj, result);
        }
    }
    result.push_back(u);
}
vector<int> topoSortDfs( int n , vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    vector<int> result;

    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            dfs(u, vis, adj, result);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}


vector<int > toposortKahns(int n , vector<vector<int>>& adj){
    vector<int> indegree(n,0);
    for( int u = 0 ; u < n ; u ++){
        for( int v : adj[u]){
            indegree[v]++;
        }
    }

    vector<int> result;
    queue<int> q;
    for( int i = 0 ; i < n ; i ++){
        if( indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
            int u = q.front();
            q.pop();    
            result.push_back(u);
            for( int v : adj[u]){
                indegree[v]--;
                if( indegree[v] == 0){
                    q.push(v);
                }
            }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

  

    return 0;
}