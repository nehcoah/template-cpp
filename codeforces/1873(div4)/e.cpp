#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](ll h) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(h - a[i], 0LL);
            if (ans > x) return false;
        }
        return ans <= x;
    };

    ll l = 1, r = 1e18 + 10;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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
