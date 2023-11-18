#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> sum(n + 1);
    ll mx = -1, mn = 1e9;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        sum[i + 1] = sum[i] + x;
    }
    ll ans = mx - mn;

    auto check = [&](int p) {
        ll a = -1, b = 1e18;
        for (int i = p; i <= n; i += p) {
            ll cur = sum[i] - sum[i - p];
            a = max(a, cur);
            b = min(b, cur);
        }
        return a - b;
    };

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = max(ans, check(i));
            ans = max(ans, check(n / i));
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


