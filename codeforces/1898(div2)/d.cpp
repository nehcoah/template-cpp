#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0, mx = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        mx = max(mx, min(a[i], b[i]));
        mn = min(mn, max(a[i], b[i]));
    }
    if (mx > mn) ans += (mx - mn) * 2;
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


