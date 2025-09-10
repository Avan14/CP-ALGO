#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int src, vector<pair<int, int>> adj[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n,1e9);
    dist[0] =0 ;
    pq.push({0,src});
    while(!pq.empty()){
        auto  [v ,d] = pq.top();
        pq.pop();
        for( auto [u , w] : adj[v]){
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] +w;
                pq.push({u,dist[u]});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}