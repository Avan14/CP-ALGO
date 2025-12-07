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
vector<int> depth;

void dfs(int node, int parent , int dep=0) {
    binaryLift[node][0] = parent;
    depth[node] = dep;
    for (int i = 1; i < 20; i++)
        binaryLift[node][i] = binaryLift[binaryLift[node][i-1]][i-1];

    for (int nei : adj[node])
        if (nei != parent)
            dfs(nei, node , 1 + dep);
}

int queryKthParent(int node, int k) {
    for (int i = 0; i < 20; i++)
        if (k & (1 << i))
            node = binaryLift[node][i];
    return node == 0 ? -1 : node;
}

void sol()
{

    ll n;
    cin >> n;
    adj.resize(n + 1);
    depth.resize(n + 1, 0);
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

    while(q--)
    {
        int u , v;
        cin >> u >> v;
        int dep_u = depth[u];
        int dep_v = depth[v];
        if(dep_u < dep_v)
            swap(u,v), swap(dep_u, dep_v);
        int diff = dep_u - dep_v;
        u = queryKthParent(u, diff);
        if(u == v)
        {
            cout << u << endl;
            continue;
        }
        for(int i = 19 ; i >= 0 ; i--)
        {
            if(binaryLift[u][i] != binaryLift[v][i])
            {
                u = binaryLift[u][i];
                v = binaryLift[v][i];
            }
        }

        cout << binaryLift[u][0] << endl;
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