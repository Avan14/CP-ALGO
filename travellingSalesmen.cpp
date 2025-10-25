#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int tsp(int mask, int pos, vector<vector<int>>& cost, vector<vector<int>>& dp) {
        int n = cost.size();
        if (mask == (1 << n) - 1) return cost[pos][0];
        if (dp[mask][pos] != -1) return dp[mask][pos];
        
        int ans = INT_MAX;
        for (int city = 0; city < n; city++) {
            if (!(mask & (1 << city))) {
                int newCost = cost[pos][city] + tsp(mask | (1 << city), city, cost, dp);
                ans = min(ans, newCost);
            }
        }
        return dp[mask][pos] = ans;
    }

    int travellingSalesman(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        return tsp(1, 0, cost, dp);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

  

    return 0;
}