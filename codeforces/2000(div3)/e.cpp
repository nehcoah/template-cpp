#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++) {
        cin >> a[i];
    }
    vector<ll> f;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f.push_back(1ll * (min(i, n - k) - max(0, i - k + 1) + 1) * (min(j, m - k) - max(0, j - k + 1) + 1));
        }
    }

    sort(f.rbegin(), f.rend());
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ans += 1ll * f[i] * a[i];
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

