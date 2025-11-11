#include <iostream>
#include <vector>
using namespace std;

int const MAX = 1e5;
int segtree[4 * MAX];
int arr[MAX];

void buildTree(int idx, int left, int right)
{
    if (left == right)
    {
        segtree[idx] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * idx + 1, left, mid);
    buildTree(2 * idx + 2, mid + 1, right);

    segtree[idx] = segtree[2 * idx + 1] + segtree[2 * idx + 2];
}

void updateTree(int updateVal, int targetIdx, int idx, int left, int right)
{
    if (left == right)
    {
        segtree[idx] = updateVal;
        return;
    }
    int mid = left + (right - left) / 2;

    if (targetIdx <= mid)
    {
        updateTree(updateVal, targetIdx, 2 * idx + 1, left, mid);
    }
    else
    {
        updateTree(updateVal, targetIdx, 2 * idx + 2, mid + 1, right);
    }
    segtree[idx] = segtree[2 * idx + 1] + segtree[2 * idx + 2];
}

int rangeSumQuery(int start, int end, int idx, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start <= left && end >= right)
    {
        return segtree[idx];
    }
    int mid = left + (right - left) / 2;
    int leftSum = rangeSumQuery(start, end, 2 * idx + 1, left, mid);
    int rightSum = rangeSumQuery(start, end, 2 * idx + 2, mid + 1, right);

    return leftSum + rightSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}

class T
{

    int size;
    vector<int> t;

public:
    T(int n, vector<int> &nums)
    {
        size = n;

        t.resize(size * 4);

        buildTree(0, 0, size - 1, nums);
    }

    void buildTree(int idx, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            t[idx] = nums[r];
            return;
        }

        int m = (l + r) / 2;

        buildTree(2 * idx + 1, l, m, nums);
        buildTree(2 * idx + 2, m + 1, r, nums);

        t[idx] = t[2 * idx + 1] + t[2 * idx + 1];
    }

    void insert(int idx, int l, int r, int tidx, int val, vector<int> &nums)
    {
        if (l == r)
        {
            t[idx] = val;
            nums[l] = val;
            return;
        }

        int m = (l + r) / 2;
        if( tidx <= m)
        insert(2 * idx + 1, l, m, tidx, val, nums);
        else 
        insert(2 * idx + 2, m + 1, r, tidx, val, nums);

        t[idx] = t[2 * idx + 1] + t[2 * idx + 1];
    }

    int q( int ql , int qr, int l , int r , int idx){
        if(qr < l || ql > r){
            return 0;
        }
        if(ql >= l && qr <= r){
            return t[idx];
        }

        int m = (l+r)/2;

        int sl = q(ql , qr , l , m , 2*idx+1);
        int sr = q(ql , qr , m+1 , r , 2*idx+2);

        return sl + sr;
    }
};