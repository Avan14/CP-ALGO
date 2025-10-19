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
            update(i, nums[i]);
        }
    }
    void update(int idx, int val)
    {   
        idx++; // 1-based indexing
        while (idx <= n)
        {
            fenw[idx] += val;
            idx += idx & (-idx);
        }
    }

    int sum(int idx)
    {   
        idx++; // 1-based indexing
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

    vector<int> nums = {1, 2, 3, 4, 5};

    FenwickTree fenwTree(nums);
    cout << "Sum of first 3 elements: " << fenwTree.sum(2) << "\n"; // Output: 6
    cout << "Range Sum (1 to 3): " << fenwTree.rangeSum(1, 3) << "\n"; // Output: 9
        

    return 0;
}