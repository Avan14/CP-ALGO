#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> dfs(int idx, int n)
{
    if (idx == 0)
    {
        return {""};
    }
    if (idx == 1)
    {
        return {"0", "1", "8"};
    }
    
    vector<string> s = dfs(idx - 2, n);
    vector<string> ans;

    vector<pair<char, char>> pairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    for (auto str : s)
    {
        for (auto &p : pairs)
        {
            if (idx == n && p.first == '0')
                continue; // skip leading zeros
            ans.push_back(string(1, p.first) + str + string(1, p.second));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter length of strobogrammatic numbers: ";
    cin >> n;

    vector<string> result = dfs(n, n);

    cout << "Strobogrammatic numbers of length " << n << ":\n";
    for (auto &num : result)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
