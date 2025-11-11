#include <iostream>
#include <vector>

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

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int n = nums.size();
        int i = 0, j = 0, skip = -1, ans = 1;
        while (j < n)
        {
            i = j;
            while (j < n && (j == i || nums[j] >= nums[j - 1]))
            {
                j++;
            }
            if (j < n && j + 1 < n && nums[j - 1] <= nums[j + 1])
            {
                skip = j;
                j++;
                while (j < n && nums[j] >= nums[j - 1])
                {
                    j++;
                }
                ans = max(ans, j - i);
            }
            else
            {
                ans = max(ans, j - i);
            }
            j = skip != -1 ? skip + 1 : j;
            skip = -1;
        }

        return ans;
    }
};
int main()
{

    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 2};
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}