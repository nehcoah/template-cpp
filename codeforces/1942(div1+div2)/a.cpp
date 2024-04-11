// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        for (int i = 0; i < n; i++) {
            cout << 1 << " \n"[i == n - 1];
        }
        return;
    }
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " \n"[i == n - 1];
        }
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
