#include <iostream>
#include <vector>

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

ll inv(ll b, ll m = 1e9 + 7, ll e = 1e9 + 5)
{
    ll r = 1;
    while (e > 0)
    {
        if (e % 2 == 1)
            r = (r * b) % m;
        b = (b * b) % m;
        e /= 2;
    }
    return r;
}

ll modExp(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
void sol() {
    string s = "aaaaabaaa";
    int n = s.size();
    int p1 = 31, p2 = 37;
    int m1 = 1e9 + 7, m2 = 1e9 + 9;

    vll hash1(n, 0), hash2(n, 0);
    vll pow1(n, 1), pow2(n, 1);

    // Precompute powers
    for (int i = 1; i < n; i++) {
        pow1[i] = (pow1[i-1] * p1) % m1;
        pow2[i] = (pow2[i-1] * p2) % m2;
    }

    // Compute prefix hashes
    hash1[0] = (s[0] - 'a' + 1);
    hash2[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
        hash1[i] = (hash1[i-1] + (s[i]-'a'+1) * pow1[i]) % m1;
        hash2[i] = (hash2[i-1] + (s[i]-'a'+1) * pow2[i]) % m2;
    }

    auto getHash = [&](int l, int r, vll &hash, vll &pow, int mod) {
        ll res = hash[r];
        if (l > 0) res = (res - hash[l-1] + mod) % mod;
        res = (res * modExp(pow[l], mod-2, mod)) % mod;
        return res;
    };

    // Compare prefix and suffix
    for (int len = 1; len < n; len++) {
        ll prefix1 = getHash(0, len-1, hash1, pow1, m1);
        ll prefix2 = getHash(0, len-1, hash2, pow2, m2);
        ll suffix1 = getHash(n-len, n-1, hash1, pow1, m1);
        ll suffix2 = getHash(n-len, n-1, hash2, pow2, m2);

        if (prefix1 == suffix1 && prefix2 == suffix2)
            cout << len << "\n";
    }
}


int main()
{
    FAST_IO;
    int t = 1;
    while (t--)
    {
        sol();
    }
    return 0;
}