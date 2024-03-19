#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 1e18;
    vector<ll> dp(n + 1, 1e18);
    dp.back() = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = min(dp[i], dp[i + 1] + min(a[i], b[i]));
        if (i < m) {
            ans = min(ans, dp[i + 1] + a[i]);
        }
    }
    cout << ans << endl;
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
