#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    vector<ll> sa(n + 1), sb(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    ranges::sort(a);
    ranges::sort(b);
    for (int i = 0; i < n; i++) {
        sa[i + 1] = sa[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
        sb[i + 1] = sb[i] + b[i];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, sa.back() - 2 * sa[i] - sb[n - i] + (sb.back() - sb[m - i]));
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
