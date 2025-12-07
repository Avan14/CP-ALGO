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

vector<vector<int>> adj;
vector<int> flattend;
map<int, int> first_occurrence;
int idx = 0;
void dfs(int node, int parent)
{
    if (first_occurrence.find(node)==first_occurrence.end())
    {
        first_occurrence[node] = idx;
    }
    idx++;
    flattend.push_back(node);
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            flattend.push_back(node);
            idx++;
        }
    }
}

template <typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<ll> arr;
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) {
            s = s << 1;
        }
        tree.resize(s);
        fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    ll val;
    Node1() { val = 0; }
    Node1(ll p1) { val = p1; }
    void merge(Node1 &l, Node1 &r) {
        val = l.val ^ r.val;
    }
};

struct Update1 {
    ll val;
    Update1(ll p1) { val = p1; }
    void apply(Node1 &a) {
        a.val = val;
    }
};

// Example usage:
// vector<ll> arr = {1, 2, 3, 4};
// SegTree<Node1, Update1> st(arr.size(), arr);
// cout << st.make_query(0, 2).val << endl;
// st.make_update(1, 5);
// cout << st.make_query(0, 2).val << endl;


void sol()
{
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    flattend.clear();
    first_occurrence.clear();
    idx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << first_occurrence[i] + 1 << " ";
    // }
    // en;
    // vout(flattend);
    SegTree<Node1, Update1> st(arr.size(), arr);
    
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