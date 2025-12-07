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

class Fwk
{

public:
    int n;
    vector<int> bit;
    Fwk(int n)
    {
        this->n = n;
        bit.resize(n+1, 0);
    }
    void update(int i, int val)
    {
        for (; i <= n; i += i & -i)
        {
            bit[i] += val;
        }
    }
    int query(int i)
    {
        int sum = 0;
        for (; i > 0; i -= (i & -i))
        {
            sum += bit[i];
        }

        return sum;
    }

    int range(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void sol()
{
    ll n;
    cin >> n;
    vector<vector<int>> vp(n, vector<int>(3));

    vector<int> coords(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vp[i][0] >> vp[i][1];
        vp[i][2] = i;
        coords[i] = vp[i][1];
    }

    // coordinate compression

    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());

    for (int i = 0; i < n; i++)
    {
        vp[i][1] = lower_bound(all(coords), vp[i][1]) - coords.begin() + 1;
    }

    sort(all(vp), [&](auto &a, auto &b)
         {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0]; });

    vector<int> contains(n, 0), contained(n, 0);

    int m = coords.size();

    Fwk ft(m), ft2(m);

    for (int i = n - 1; i >= 0; i--)
    {
        contains[vp[i][2]] = ft.query(vp[i][1]);
        ft.update(vp[i][1], 1);
    }

    for (int i = 0; i < n; i++)
    {
        contained[vp[i][2]] = ft2.range(vp[i][1], m);
        ft2.update(vp[i][1], 1);
    }

    vout(contains);
    vout(contained);
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