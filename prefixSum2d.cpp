#include <iostream>
#include <vector>
using namespace std;


void calculate2dPrefixSum(const vector<vector<int>> &matrix, vector<vector<int>> &prefixSum) {
    int n = matrix.size();
    int m = matrix[0].size();
    prefixSum.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefixSum[i][j] = matrix[i - 1][j - 1] 
                            + prefixSum[i - 1][j] 
                            + prefixSum[i][j - 1] 
                            - prefixSum[i - 1][j - 1];
        }
    }
}

int query2dPrefixSum(const vector<vector<int>> &prefixSum, int x1, int y1, int x2, int y2) {
    return prefixSum[x2 + 1][y2 + 1] 
         - prefixSum[x1][y2 + 1] 
         - prefixSum[x2 + 1][y1] 
         + prefixSum[x1][y1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

  

    return 0;
}