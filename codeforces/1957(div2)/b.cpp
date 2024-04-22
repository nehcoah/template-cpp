//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return;
    }
    vector<int> ans(n);
    int j = 0;
    while ((1 << j) - 1 <= k) j += 1;
    ans[0] = (1 << (j - 1)) - 1;
    ans[1] = k - ans[0];
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
