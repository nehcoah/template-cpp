#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 1ll * n * (n + 1) / 2;
    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        int t = lower_bound(sum.begin(), sum.end(), sum[i] + x + 1) - sum.begin();
        dp[i] = (t == n + 1 ? 0 : dp[t] + 1);
        ans -= dp[i];
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
