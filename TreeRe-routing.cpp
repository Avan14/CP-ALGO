#include <iostream>
#include <vector>

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

vector<int> adj[200005];
vector<int> depth(200005, 0), height(200005, 0);

void depthDFS(int node, int parent)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        depthDFS(child, node);
        depth[node] = max(depth[node], 1 + depth[child]);
    }
}

void reRouteDFS(int node, int parent)
{
    int mx1 = -1, mx2 = -1, mxchild = -1;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        if (depth[child] + 1 > mx1)
        {
            mx2 = mx1;
            mx1 = depth[child] + 1;
            mxchild = child;
        }
        else if (depth[child] + 1 > mx2)
        {
            mx2 = depth[child] + 1;
        }
    }
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        int longest = (child == mxchild) ? mx2 : mx1;
        height[child] = 1 + max(height[node], longest);
        reRouteDFS(child, node);
    }
}

void sol()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    depthDFS(1, 0);
    reRouteDFS(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << max(height[i], depth[i]) << " ";
    }
    en
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