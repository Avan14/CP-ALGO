#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

typedef long long ll;

#define all(x) (x).begin(), (x).end()

#define debug(x) cerr << #x << " = " << (x) << endl;
#define vout(a)                          \
    for (int i = 0; i < (a).size(); ++i) \
        cout << a[i] << ' ';             \
    cout << endl;
#define yes cout << 'Y' << 'E' << 'S' << endl;
#define no cout << 'N' << 'O' << endl;
#define en cout << endl;

ll gcd(ll temp_a, ll temp_b) { return temp_b == 0 ? temp_a : gcd(temp_b, temp_a % temp_b); }
ll lcm(ll temp_a, ll temp_b) { return (temp_a / gcd(temp_a, temp_b)) * temp_b; }
// -------------------------------------------------------------------------------------------------
vector<vector<int>> adj;

void sol()
{
    ll n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    function<void(int, int)> dfs = [&](int node, int parent)
    {
        for (auto neigh : adj[node])
        {
            if (neigh == parent)
                continue;
            dfs(neigh, node);

            // if node is not being selected as red get
            // max out of their children
            dp[node][0] += max(dp[neigh][0], dp[neigh][1]);
        }
        for (auto neigh : adj[node])
        {
            if (neigh == parent)
                continue;
            // if i mark this node as red
            // it will be selecting one of the other edges as not picked

            dp[node][1] = max(dp[node][1], 1 + dp[node][0] + dp[neigh][0] - max(dp[neigh][0], dp[neigh][1]));
        }
    };

    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

int main()
{
    FAST_IO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}