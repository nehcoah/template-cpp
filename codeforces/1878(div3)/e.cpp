#include "bits/stdc++.h"

using namespace std;
using ll = long long;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector nxt(n + 1, vector<int>(30, n));
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        for (int j = 0; j < 30; j++) {
            if ((a[i] >> j & 1) == 0) nxt[i][j] = i;
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, k; cin >> l >> k;
        l--;
        int ans = l, mx = n;
        for (int j = 29; j >= 0; j--) {
            if (k >> j & 1) mx = min(mx, nxt[l][j]);
            else ans = max(ans, min(mx, nxt[l][j]));
        }
        ans = max(ans, mx);
        if (ans == l) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << endl;
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
