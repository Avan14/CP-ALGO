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
void sol()
{
    ll n;
    cin >> n;
    ll totalCitizens;
    cin >> totalCitizens;
    vector<int> citizens(n + 1), happinessIndex(n + 1), sad(n + 1, 0);

    vector<int> adj[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> citizens[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> happinessIndex[i + 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool flag = true;
    function<void(int, int)> dfs = [&](int node, int parent)
    {
        // debug("enterd");
        // debug(node);
        // debug(parent);
        // debug(citizens[node]);
        for (int neigh : adj[node])
        {
            if (neigh == parent)
                continue;
            dfs(neigh, node);
            citizens[node] += citizens[neigh];
            if (!flag)
            {
                return;
            }
            // hi = happy[i] - sad[i]
            // total = happy[i] + sad[i];
        }

        // checks

        if (((citizens[node] - happinessIndex[node])) % 2 != 0)
        {
            debug("issue-1");
            flag = false;
            return;
        }
        int currSad = (citizens[node] - happinessIndex[node]) / 2;
        if (abs(happinessIndex[node]) > citizens[node])
        {
            debug("issue-2");

            flag = false;
            return;
        }
        

        sad[node] = currSad;
    };

    dfs(1, 1);
    cout << (flag ? "YES\n" : "NO\n");
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