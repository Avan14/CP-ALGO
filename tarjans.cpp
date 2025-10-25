#include <iostream>
#include <vector>
using namespace std;




class Solution {

private :
    int timer = 0;
public :
    void dfs( int u , int parent , vector<bool> &vis,vector<int>&dis , vector<int>&low_dis,vector<vector<int>> &adj,vector<vector<int>> &bridges){
        vis[u] = true;
        dis[u] = low_dis[u] = timer++;
        
        for( int v : adj[u]){
            if(v==parent){
                continue;
            }
            if(!vis[v]){
                dfs(v,u,vis,dis,low_dis,adj,bridges);
                low_dis[u] = min(low_dis[u],low_dis[v]);

                if( low_dis[v] > dis[u]){
                    bridges.push_back({v,u});
                }
            }
            else{
                low_dis[u] = min(low_dis[u],dis[v]);
            }
        }
    }
    vector<vector<int>> tarjans(int n , vector<vector<int>>& connections){
        vector<vector<int>> adj(n);
        for( auto & con : connections ){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }

        vector<bool> vis(n,false);
        vector<int> dis(n,-1) , low_dis(n,-1);
        vector<vector<int>> bridges;


        for( int u = 0 ; u < n ; u ++)
        {
            if(!vis[u]){
                dfs( u , -1 ,vis,dis,low_dis,adj,bridges);
            }
        }
        return bridges;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

  

    return 0;
}