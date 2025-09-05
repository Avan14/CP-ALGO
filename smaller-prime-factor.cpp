#include <bits/stdc++.h>
using namespace std;

// Precomputes smallest prime factor (spf) for every number <= N
const int N = 1e6 + 5;  // limit (can adjust)
int spf[N];             // spf[i] will store smallest prime factor of i

void computeSPF() {
    for (int i = 1; i < N; i++) spf[i] = i;  // initialize with itself
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i; // update only if not updated
            }
        }
    }
}

// Example: Factorize a number using SPF
vector<int> getFactorization(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computeSPF();

    int num = 84;
    auto factors = getFactorization(num);

    cout << "Prime factors of " << num << " : ";
    for (int f : factors) cout << f << " ";
    cout << "\n";

    return 0;
}
