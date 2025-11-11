#include <bits/stdc++.h>

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

const int MAXN = 1e5 + 5;
int binaryLift[MAXN][20];
vector<vector<int>> adj;

void dfs(int node, int parent) {
    binaryLift[node][0] = parent;
    for (int i = 1; i < 20; i++)
        binaryLift[node][i] = binaryLift[binaryLift[node][i-1]][i-1];

    for (int nei : adj[node])
        if (nei != parent)
            dfs(nei, node);
}

int query(int node, int k) {
    for (int i = 0; i < 20; i++)
        if (k & (1 << i))
            node = binaryLift[node][i];
    return node == 0 ? -1 : node;
}

void sol()
{

    ll n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    int q;
    cin >> q;
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        cout << query(node, k);
    }
}

int main()
{
    FAST_IO;
    int t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}