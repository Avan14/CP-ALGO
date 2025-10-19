#include <iostream>
#include <vector>
using namespace std;

class FenwickTree
{
private:
    int n;
    vector<int> fenw;

public:
    FenwickTree(vector<int> &nums)
    {

        n = nums.size();
        fenw.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            update(i + 1, nums[i]);
        }
    }
    void update(int idx, int val)
    {
        while (idx <= n)
        {
            fenw[idx] += val;
            idx += idx & (-idx);
        }
    }

    int sum(int idx)
    {
        int sum = 0;
        while (idx >= 1)
        {
            sum += fenw[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    int rangeSum(int left, int right)
    {
        return sum(right) - sum(left - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}