#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] = c[i];
    }

    ll ans = 0;
    for (auto [k, v] : mp) {
        ans = max(ans, k * min<ll>(v, m / k));
        if (mp.contains(k + 1)) {
            int w = mp[k + 1];
            auto x = min<ll>(v, m / k);
            auto y = min<ll>(w, (m - 1ll * k * x) / (k + 1));
            auto add = min<ll>(x, w - y);
            ans = max(ans, min(m, x * k + y * (k + 1) + add));
        }
    }
    cout << ans << "\n";
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

