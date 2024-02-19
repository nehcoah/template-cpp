#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> f(n + 1, n + 1), d(n + 2);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        f[r] = min(f[r], l);
        d[l] += 1;
        d[r + 1] -= 1;
    }
    for (int i = 0; i <= n; i++) {
        d[i + 1] += d[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        f[i] = min(f[i], f[i + 1]);
    }
    vector<int> dp(n + 1);
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = d[i] + dp[f[i] - 1];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp.back() << endl;
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

