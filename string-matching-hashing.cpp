#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fr(i, n) for (int i = 0; i < n; i++)

#define debug(x) cerr << #x << " = " << (x) << endl;
#define vin(a)                           \
    for (int i = 0; i < (a).size(); ++i) \
        cin >> a[i];
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

ll base[100002] = {0};

void precompute()
{
    base[0] = 1;
    ll pow = 31;
    for (int i = 1; i <= 10000; i++)
    {
        base[i] = (pow * base[i - 1]) % MOD;
    }
}

void sol()
{
    string s = "cdcdcdabc";
    string t = "cdcd";
    int n = s.size();
    int m = t.size();

    vll pref_hash(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pref_hash[i] = (pref_hash[i - 1] + ((s[i - 1] - 'a' + 1) * base[i - 1]) % MOD) % MOD;
    }

    ll pattern_hash = 0;
    for (int i = 0; i < m; i++)
    {
        pattern_hash = (pattern_hash + ((t[i] - 'a' + 1) * base[i]) % MOD) % MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {
        ll sub_hash = (pref_hash[i + m] - pref_hash[i] + MOD) % MOD;
        if (sub_hash == (pattern_hash * base[i]) % MOD)
        {
            debug(i); 
        }
    }

    en;
}

int main()
{
    FAST_IO;
    precompute();
    int t = 1;
    while (t--)
    {
        sol();
    }
    return 0;
}