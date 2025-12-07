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

vector<vector<int>> adj(200005), up(200005, vector<int>(20, 0));
vector<int> d(200005, 0);
vector<int> pref(200005, 0);

void calc(int v, int p, int dep = 0)
{
    up[v][0] = p;
    d[v] = dep;
    for (int i = 1; i <= 19; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (auto u : adj[v])
    {
        if (u != p)
        {
            calc(u, v, dep + 1);
        }
    }
}

int qhelp(int u, int k)
{
    for (int i = 0; i < 20; i++)
    {
        if (k & (1 << i))
            u = up[u][i];
    }
    return u;
}
int query(int v, int u)
{
    if (d[u] > d[v])
    {
        swap(u, v);
    }
    int diff = d[v] - d[u];
    v = qhelp(v, diff);
    if (u == v)
    {
        return u;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void settleDFS(int v, int p)
{
    for (auto u : adj[v])
    {
        if (u != p)
        {
            settleDFS(u, v);
            pref[v] += pref[u];
        }
    }
}

void sol()
{

    ll n;
    cin >> n;
    int q;
    cin >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    calc(1, 0);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int lca = query(u, v);
        pref[u]++;
        pref[v]++;
        pref[lca]--;
        if (up[lca][0] != 0)
            pref[up[lca][0]]--;
    }

    settleDFS(1, 0);

    for (int u = 1; u <= n; u++)
    {
        cout << pref[u] << " ";
    }

    en;
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