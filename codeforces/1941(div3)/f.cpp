#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll l, r, mn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            if (a[i] - a[i - 1] > mn) {
                l = a[i - 1], r = a[i];
                mn = a[i] - a[i - 1];
            }
        }
    }
    vector<ll> d(m), f(k);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());
    ll ans = mn;
    for (ll x : d) {
        ll t = ((l + r) >> 1) - x;
        auto it = lower_bound(f.begin(), f.end(), t);
        if (it != f.end()) {
            if (x + *it >= l && x + *it <= r) {
                ans = min(ans, max(x + *it - l, r - *it - x));
            }
        }
        if (it != f.begin()) {
            it = prev(it);
            if (x + *it >= l && x + *it <= r) {
                ans = min(ans, max(x + *it - l, r - *it - x));
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != l) {
            ans = max(ans, a[i + 1] - a[i]);
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
