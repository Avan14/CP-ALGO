#include <iostream>
#include <vector>

using namespace std;

vector<int> bellmanFord(vector<vector<int>> &edges, int n, int src)
{
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // to check fro negative cycles

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            cout << " neg cycle";
            return {-1};
        }
    }

    return dist;
}

vector<vector<int>> floydWarshal(vector<vector<int>> &edges, int n)
{

    vector<vector<int>> dist(n, vector<int>(n, 1e4));

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (auto it : edges)
    
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        dist[u][v] = wt;
    }

    for (int k = 0; k < n; k++)
    {
        for (int v = 0; v < n; v++)
        {
            for (int u = 0; u < n; u++)
            {
                dist[u][v] =  min(dist[u][v] , dist[u][k] + dist[k][v]);
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

    // test case

    // vector<vector<int>> edges = {
    //     {0, 1, 12},
    //     {0, 2, 4},
    //     {1, 2, 3},
    //     {1, 3, 2},
    //     {1, 4, 2},
    //     {3, 2, 5},
    //     {3, 1, 1},
    //     {4, 3, 3}};
    // int n = 5;
    // int src = 0;
    // vector<int> dist = bellmanFord(edges, n, src);
    // for (int i = 0; i < dist.size(); i++)
    // {
    //     cout << "Distance from source to " << i << " is " << dist[i] << "\n";
    // }

    // test case for floyd warshal

    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 3, 10},
        {1, 2, 3},
        {2, 3, 1}};
    int n = 4;
    vector<vector<int>> dist = floydWarshal(edges, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 1e4)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}