#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, b, x;
    cin >> n >> b >> x;
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        mp[c]++;
        mx = max(mx, c);
    }

    auto check = [&](int t) {
        ll score = -1ll * (t - 1) * x;
        for (auto [k, v] : mp) {
            if (k == 1) continue;
            int base = k / t, left = k % t;
            ll cur = 0;
            if (left == 0) cur = 1ll * base * (k - base) * t;
            else cur = 1ll * left * (base + 1) * (k - base - 1) + 1ll * (t - left) * base * (k - base);
            cur = cur * b / 2;
            score += cur * v;
        }
        return score;
    };

    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans = max(ans, check(i));
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

