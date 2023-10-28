#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1);
    vector<int> b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ranges::sort(a);
    ranges::sort(b);
    ll ans = 0, j = 0;
    int mx = 0;
    for (int i = 0; i < n - 1 && j < n; i++, j++) {
        while (j < n && a[i] >= b[j]) mx = max(mx, b[j]), j++;
        if (j != n) ans++;
    }
    if (j < n) mx = max(mx, b[j]);
    ans = (ll)(n - 1 - ans) * m;
    ans += max(0, m - mx + 1);
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

