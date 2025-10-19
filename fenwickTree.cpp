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
    void updateRange(int left, int right, int val)
    {
        update(left, val);
        update(right + 1, -val);
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
    fenwTree.update(2, 5); // Increment index 2 by 5
    cout << "Sum after update at index 2: " << fenwTree.sum(2) << "\n"; // Output: 11
    fenwTree.updateRange(1, 3, 2); // Increment range [1, 3] by 2
    cout << "Range Sum (1 to 3) after range update: " << fenwTree.rangeSum(1, 3) << "\n"; // Output: 15
        

    return 0;
}