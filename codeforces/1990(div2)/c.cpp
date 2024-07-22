#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int t = 0; t < 2; t++) {
        vector<int> vis(n + 1);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i];
            if (vis[a[i]]) mx = max(mx, a[i]);
            vis[a[i]] = 1;
            a[i] = mx;
        }
    }
    for (int i = 0; i < n; i++) {
        ans += 1ll * (n - i) * a[i];
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
