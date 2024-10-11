#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int x = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1 && (x == -1 || a[i] > a[x])) {
            x = i;
        }
    }

    ll ans = 0;
    if (x != -1) {
        ll cur = a[x] + k;
        auto c = a;
        c[x] = 1.5e9;
        sort(c.begin(), c.end());
        cur += c[(n - 2) / 2];
        ans = cur;
    }

    x = max_element(a.begin(), a.end()) - a.begin();
    const int tot = n - 1 - (n - 2) / 2;
    auto check = [&](ll t) {
        vector<ll> p;
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            if (a[i] >= t) {
                p.push_back(0);
                continue;
            }
            if (b[i] == 0) continue;
            p.push_back(t - a[i]);
        }
        if (p.size() < tot) return false;
        sort(p.begin(), p.end());
        ll y = accumulate(p.begin(), p.begin() + tot, 0ll);
        return y <= k;
    };

    ll l = 0, r = 2e9;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    ans = max<ll>(ans, a[x] + l);
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

