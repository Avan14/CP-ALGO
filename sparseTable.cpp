#include <iostream>
#include <vector>

// LETS DEFINE THE DP TABLE

// ST[i][j] = min( a[i to i + 2^j -1])

// base case : j = 0
// ST[i][0] = a[i]

using namespace std;

// sparse table are espically used in case of idempotent functions

// Sparse Table for Range Minimum Query

//
class SparseTable
{
private:
    int n;
    int maxLog;
    vector<vector<int>> st;

public:
    SparseTable(const vector<int> &nums)
    {
        n = nums.size();
        maxLog = log2(n) + 1;
        st.resize(n, vector<int>(maxLog));

        // Initialize the first column of the sparse table
        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }

        // Fill the sparse table
        for (int j = 1; j < maxLog; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int log2(int x)
    {
        // return 31 - __builtin_clz(x);
        // return 63 - __builtin_clzll(x);
        int res = 0;
        while ((1 << res) <= x)
            res++;
        return res - 1;
    }
    // Query the minimum in the range [L, R]
    int rangeMinQuery(int L, int R)
    {
        int j = log2(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

class Sparet
{
private:
    int n;
    int m;
    vector<vector<int>> st;

    int log2(int n)
    {
        long long pow = 1;
        int cnt = 0;
        while (pow <= n)
        {
            pow *= 2;
            cnt++;
        }

        return cnt - 1;
    }

public:
    Sparet(vector<int> &nums)
    {
        n = nums.size();
        m = log2(n) + 1;

        st.assign(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << j) - 1][j - 1]);
            }
        }
    }  
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}